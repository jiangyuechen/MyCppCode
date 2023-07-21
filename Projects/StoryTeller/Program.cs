using MySql.Data.MySqlClient;
using MySql.Data;
using System.Runtime.InteropServices;
using System.Security.Permissions;
namespace StoryTeller
{
    using StoryLine = LinkedList<StoryEvent>;
    using StoryLineNode = LinkedListNode<StoryEvent>;
    public class Story
    {
        private static int StNum = 0; // 故事数量，用于分配编号
        private string StName; // 故事名称
        private int StId; // 故事编号
        private StoryLine StEvents;
        public int GetStId
        {
            get => StId;
        }
        public string GetStName
        {
            get => StName;
        }
        public StoryLine GetStEvents
        {
            get => StEvents;
        }
        public Story()
        {
            StId = StNum;
            StNum++;
            StName = "[unnamed story #" + StId.ToString() + "]"; 
            StEvents = new StoryLine();
        }
        public Story(string _StName)
        {
            StNum++;
            StId = StNum;
            StName = _StName;
            StEvents = new StoryLine();
        }
        public void AddEventLast(StoryEvent _stev)
        {
            StoryLineNode stev = new StoryLineNode(_stev);
            StEvents.AddLast(stev);
        }
        public void AddEventFirst(StoryEvent _stev)
        {
            StoryLineNode stev = new StoryLineNode(_stev);
            StEvents.AddFirst(stev);
        }
        public StoryLineNode? Find(int _stid)
        {
            foreach (StoryEvent _var_event in StEvents)
            {
                if (_var_event.GetEvId == _stid)
                {
                    return new StoryLineNode(_var_event);
                }
            }
            return null;
        }
        public int AddEventBefore(StoryEvent _stev, int _stid) 
        {
            StoryLineNode? _tar_node = Find(_stid);
            if ( _tar_node != null )
            {
                StEvents.AddBefore(_tar_node, _stev);
                return 0;
            }
            else
            {
                return 1;
            }
        }
        public int Refresh() // 
        {
            return 0;
        }
    }
    public class StoryEvent
    {
        private string? EvDescription;
        private string EvName;
        private static int EvNum = 0;
        private int EvId;
        public int GetEvId
        {
            get => EvId;
        }
        public string GetEvName
        {
            get => EvName;
        }
        public string GetEvDescription
        {
            get
            {
                if ( EvDescription == null ) { return "null"; }
                else return EvDescription;
            }
        }
        private int NewEvent()
        {
            EvNum++;
            return EvNum;
        }
        public StoryEvent(string? _evName, string? _evDescription)
        {
            EvId = NewEvent();
            EvDescription = _evDescription;
            if (_evName != null )
            {
                EvName = _evName;
            }
            else
            {
                EvName = "[unnamed story event #" + EvId.ToString() + "]";
            }
        }
    }
    public static class StoryTeller
    {
        private static MySqlCommand DataMaker(string StName, int StId, MySqlConnection msc)
        {
            return new MySqlCommand("use StoryTeller; insert into Story(StName, StId) values('" + StName + "'," +  StId + ");", msc);
        }
        private static MySqlCommand DataDeleter(string StName, int StId, MySqlConnection msc)
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
            //        Console.WriteLine(dr.GetString("StName") + dr.GetInt32("StId"));
            //    }
            //    conn.Close();
            //}
            //catch (MySqlException ex)
            //{
            //    Console.WriteLine(ex.Message);
            //}
            Story story = new Story();
            StoryEvent storyEvent1 = new StoryEvent("我出生了", "2004年12月1日，我出生了");
            story.AddEventLast(storyEvent1);
            StoryEvent storyEvent2 = new StoryEvent("我去世了", null);
            story.AddEventLast(storyEvent2);
            StoryEvent storyEvent3 = new StoryEvent("我活着", "起起落落落落落落落落落落落落的人生");
            story.AddEventBefore(storyEvent3, 1);
            StoryLine stl = story.GetStEvents;
            foreach (StoryEvent line in stl) 
            {
                Console.WriteLine("事件 {0} || 标题 : {1} || 内容 : {2}", line.GetEvId, line.GetEvName, line.GetEvDescription);
            }
        }
    }
}