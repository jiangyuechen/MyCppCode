using MySql.Data.MySqlClient;
using System.ComponentModel;
using System.ComponentModel.DataAnnotations;
using System.ComponentModel.Design;
using System.Data;
using System.Security.Cryptography.X509Certificates;

namespace StoryTeller
{
    using StoryLine = LinkedList<StoryEvent>;
    using StoryLineNode = LinkedListNode<StoryEvent>;
    using TimeTable = List<KeyValuePair<int, List<StoryEvent>>>;

    public class Object
    {
        public const int MIN_TIME = 1;
        public const int MAX_TIME = 2147483647;
        public const int NULL_TIME = 0;
        public Object()
        { }
    }
    public class Attribute : Object
    {
        public string key, value;
        /// <summary>
        /// Constructor of an Attribute.  
        /// </summary>
        /// <param name="_key"></param>
        /// <param name="_value"></param>
        public Attribute(string? _key = null, string? _value = null)
        {
            key = _key ?? "<no-key>";
            value = _value ?? "<no-value>";
        }
    }
    public class Character : Object
    {
        public List<Attribute> attributes;
        public Character(List<Attribute>? _attributes = null)
        {
            attributes = _attributes ?? new List<Attribute>();
        }
        /// <summary>
        /// Add an attribute. If there is already an attribute with the same key, it will be altered as the new attribute.
        /// </summary>
        /// <param name="_attrib">The attribute to be added.</param>
        public void AddAttribute(Attribute _attrib)
        {
            if (FindAttribute(_attrib.key) == null)
                attributes.Add(_attrib);
            else
                AlterAttribute(_attrib.key, _attrib.value);
        }
        public void AddAttribute(string _key, string _value)
        {
            AddAttribute(new Attribute(_key, _value));
        }
        /// <summary>
        /// Add multiple attributes once.
        /// </summary>
        /// <param name="_attribs">The attributes to be added.</param>
        public void AddAttributes(List<Attribute> _attribs)
        {
            foreach (var _a in _attribs)
            {
                AddAttribute(_a);
            }
        }
        /// <summary>
        /// Delete a certain attribute of a character.
        /// </summary>
        /// <param name="_key">The key of which you want to delete.</param>
        public void DeleteAttribute(string _key)
        {
            foreach (var _a in attributes)
            {
                if (_a.key == _key)
                {
                    attributes.Remove(_a);
                    break;
                }
            }
        }
        /// <summary>
        /// Find a certain attribute with the key given.
        /// </summary>
        /// <param name="_key">The key.</param>
        /// <returns>The certain attribute (but not its reference), or null if unfound. </returns>
        public Attribute? FindAttribute(string _key)
        {
            foreach (var _a in attributes)
            {
                if (_a.key == _key)
                    return _a;
            }
            return null;
        }
        /// <summary>
        /// Alter the attribute with the key given, so that its value is changed.
        /// </summary>
        /// <param name="_key">The attribute to be altered.</param>
        /// <param name="_new_value">The new value to alter.</param>
        public void AlterAttribute(string _key, string _new_value)
        {
            AlterAttribute(new Attribute(_key, _new_value));
        }
        public void AlterAttribute(Attribute _new_attrib)
        {
            Attribute? _obj_attr = FindAttribute(_new_attrib.key);
            if (_obj_attr != null)
            {
                DeleteAttribute(_new_attrib.key);
                Attribute _altered_attr = new Attribute(_new_attrib.key, _new_attrib.value);
                attributes.Add(_altered_attr);
            }
        }
    }
    public unsafe class SubCharacter : Character
    {
        public Character* p_parent;
        public SubCharacter(Character _parent, List<Attribute>? _attributes = null) : base (_attributes)
        {
            p_parent = &_parent;
        }
        public SubCharacter(Character* _p_parent, List<Attribute>? _attributes = null) : base(_attributes)
        {
            p_parent = _p_parent;
        }
        ~SubCharacter()
        {
            p_parent = null;
        }
    }
    public unsafe class Link<T> : Object where T : Object
    {
        public T* p_front;
        public T* p_back;
        public Link() : base()
        {
            p_front = null;
            p_back = null;
        }
        public Link(T* _p_front, T* _p_back) : base()
        {
            p_front = _p_front;
            p_back = _p_back;
        }
        ~Link()
        {
            p_front = null;
            p_back = null;
        }
        public void AlterFront(T* _p_new_front) => p_front = _p_new_front;
        public void AlterBack(T* _p_new_back) => p_back = _p_new_back;
        public T GetFront() => *p_front;
        public T GetBack() => *p_back;
        public T* GetFrontPointer() => p_front;
        public T* GetBackPointer() => p_back;
    }
    public class Story : Object
    {
        public string story_name; // 故事名称
        public StoryLine story_events;
        public List<Character> story_characters;
        public List<Link<StoryEvent>> story_event_links;
        public List<Link<Character>> story_character_links;
        public Story(string? _story_name = null, StoryLine? _story_events = null, List<Character>? _characters = null, List<Link<StoryEvent>>? _story_event_links = null, List<Link<Character>>? _story_character_links = null)
        {
            story_name = _story_name ?? "<no-name>";
            story_events = _story_events ?? new StoryLine();
            story_characters = _characters ?? new List<Character>();
            story_event_links = _story_event_links ?? new List<Link<StoryEvent>>();
            story_character_links = _story_character_links ?? new List<Link<Character>>();
        }
        public void AddEventLast(ref StoryEvent _stev)
        {
            StoryLineNode stev = new(_stev);
            story_events.AddLast(stev);
        }
        public void AddEventFirst(ref StoryEvent _stev)
        {
            StoryLineNode stev = new(_stev);
            story_events.AddFirst(stev);
        }
        /// <summary>
        /// Find a certain StoryLineNode.
        /// </summary>
        /// <param name="_stid">The identifier of the StoryEvent of StoryLineNode.</param>
        /// <returns>The target StoryLineNode or null if unfound.</returns>
        public StoryLineNode? FindNode(int _stid)
        {
            StoryLineNode? _i = story_events.First;
            if (_i == null) 
                return null;
            for (; _i != null; _i = _i.Next)
            {
                if (_i.Value.GetEventIdentifier == _stid)
                    return _i;
            }
            return null;
        }
        /// <summary>
        /// Find a certain StoryEvent.
        /// </summary>
        /// <param name="_stid">The identifier of the StoryEvent.</param>
        /// <returns>The target StoryEvent or null if unfound.</returns>
        public StoryEvent? FindEvent(int _stid)
        {
            StoryLineNode? _sln = FindNode(_stid);
            if (_sln == null) 
                return null;
            else 
                return _sln.Value;
        }
        /// <summary>
        /// Add a StoryEvent before a certain StoryEvent.
        /// </summary>
        /// <param name="_stev">The StoryEvent to be added.</param>
        /// <param name="_stid">The identifier of the StoryEvent, before which the new StoryEvent is added.</param>
        /// <returns>0 = Succeed; 1 = Failed</returns>
        public int AddEventBefore(ref StoryEvent _stev,int _stid)
        {
            StoryLineNode? _tar_node = FindNode(_stid);
            if (_tar_node != null)
            {
                story_events.AddBefore(_tar_node, _stev);
                return 0;
            }
            else return 1;
        }
        /// <summary>
        /// Add a StoryEvent after a certain StoryEvent.
        /// </summary>
        /// <param name="_stev">The StoryEvent to be added.</param>
        /// <param name="_stid">The identifier of the StoryEvent, after which the new StoryEvent is added.</param>
        /// <returns>0 = Succeed; 1 = Failed</returns>
        public int AddEventAfter(ref StoryEvent _stev, int _stid)
        {
            StoryLineNode? _tar_node = FindNode(_stid);
            if (_tar_node != null)
            {
                story_events.AddAfter(_tar_node, _stev);
                return 0;
            }
            else return 1;
        }
        /// <summary>
        /// Delete a certain StoryEvent.
        /// </summary>
        /// <param name="_stid">The identifier of the StoryEvent to be deleted.</param>
        /// <returns>0 = Succeed; 1 = Failed</returns>
        public int DeleteEvent(int _stid)
        {
            StoryLineNode? _tar_node = FindNode(_stid);
            if (_tar_node != null)
            {
                story_events.Remove(_tar_node);
                return 0;
            }
            else return 1;
        }
    }


    public class TimeOrderStory : Story
    {

        public int start_time = MIN_TIME;
        public int end_time = MAX_TIME;
        public List<StoryEvent>[] timetable;
        public TimeOrderStory() : base() 
        {
            timetable = new List<StoryEvent>[MAX_TIME];
        }
        public TimeOrderStory(string? _story_name = null, 
            StoryLine? _story_events = null, 
            List<Character>? _characters = null,
            List<Link<StoryEvent>>? _story_event_links = null, 
            List<Link<Character>>? _character_links = null,
            List<StoryEvent>[]? _timetable = null)
            : base(_story_name, _story_events, _characters, _story_event_links, _character_links) 
        {
            timetable = new List<StoryEvent>[MAX_TIME];
            if (_timetable == null && _story_events != null)
            {
                foreach (var _obj in _story_events)
                {
                    timetable[_obj.GetEventTime].Add(_obj);
                }
            }
            
        }
        public List<StoryEvent> GetEventsByTime(int _time)
        {
            return timetable[_time];
        }
        public void AddEventByTime(StoryEvent _story_event, int _time)
        {
            timetable[_time].Add(_story_event);
        }
        public void AddEventsByTime(List<StoryEvent> _story_events, int _time)
        {
            timetable[_time].AddRange(_story_events);
        }
    }
    public class StoryEvent : Object
    {
        public string? event_description;
        private string event_name;
        private static int event_count = 0;
        private int event_identifier;
        private int? event_time;
        public int GetEventIdentifier
        {
            get => event_identifier;
            set => event_identifier = value;
        }
        public string GetEventName
        {
            get => event_name;
            set => event_name = value;
        }
        public string GetEventDescription
        {
            get
            {
                if (event_description == null) { return "null"; }
                else return event_description;
            }
            set => event_description = value; 
        }
        public int GetEventTime
        {
            get {
                return event_time ?? NULL_TIME;
            }
            set {
                if (value < MIN_TIME && value != NULL_TIME)
                    event_time = MIN_TIME;
                else if (value > MAX_TIME)
                    event_time = MAX_TIME;
                else
                    event_time = value;
            }
        }
        private static int NewEvent()
        {
            event_count++;
            return event_count;
        }
        public StoryEvent(string? _event_name = null, string? _event_description = null, int? _event_time = null)
        {
            event_identifier = NewEvent();
            event_description = _event_description;
            if (_event_name != null)
            {
                event_name = _event_name;
            }
            else
            {
                event_name = "[unnamed story event #" + event_identifier.ToString() + "]";
            }
            if (_event_time != null)
            {
                if (_event_time < MIN_TIME && _event_time != NULL_TIME)
                    event_time = MIN_TIME;
                else if (_event_time > MAX_TIME)
                    event_time = MAX_TIME;
                else
                    event_time = _event_time;
            }
            else
                event_time = NULL_TIME;
        }
    }

    public unsafe static class StoryTeller
    {
        private static MySqlCommand DataMaker(string StoryName, int StoryIdentifier, MySqlConnection msc)
        {
            return new MySqlCommand("use StoryTeller; insert into Story(StoryName, StoryIdentifier) values('" + StoryName + "'," + StoryIdentifier + ");", msc);
        }
        private static MySqlCommand DataDeleter(string StoryName, int StoryIdentifier, MySqlConnection msc)
        {
            return new MySqlCommand("use StoryTeller; delete from Story where ");
        }
        public static void Main(string[] args)
        {
            //try
            //{
            //    MySqlConnection conn = new MySqlConnection(
            //    "Server = 127.0.0.1; port = 1145; user = root; password = Kxcrdcnl1");
            //    conn.Open();
            //    MySqlCommand comm = new MySqlCommand("use StoryTeller; select * from Story;", conn);
            //    DataMaker("原神启动", 123456, conn).ExecuteNonQuery();
            //    MySqlDataReader dr = comm.ExecuteReader();
            //    while (dr.Read())
            //    {
            //        Console.WriteLine(dr.GetString("StoryName") + dr.GetInt32("StoryIdentifier"));
            //    }
            //    conn.Close();
            //}
            //catch (MySqlException ex)
            //{
            //    Console.WriteLine(ex.Message);
            //}
            //Story story = new();
            //StoryEvent storyEvent1 = new("我出生了", "2004年12月1日，我出生了");
            //story.AddEventLast(ref storyEvent1);
            //StoryEvent storyEvent2 = new("我去世了", null);
            //story.AddEventLast(ref storyEvent2);
            //StoryEvent storyEvent3 = new("我活着", "起起落落落落落落落落落落落落的人生");
            //story.AddEventBefore(ref storyEvent3, 1);
            //story.DeleteEvent(3);
            //StoryLine stl = story.GetStoryEvents;
            //foreach (StoryEvent line in stl)
            //{
            //    Console.WriteLine("事件 {0} || 标题 : {1} || 内容 : {2}", line.GetEventIdentifier, line.GetEventName, line.GetEventDescription);
            //}
            Character Vanessa = new Character();
            Vanessa.AddAttribute("Gender", "Female");
            Vanessa.AddAttribute("Identity", "Builder");

        }
    }
}