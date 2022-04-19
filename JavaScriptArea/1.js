function Vector (x, y, z) {
    Vector.prototype.x = x;
    Vector.prototype.y = y;
    Vector.prototype.z = z;
    return this;
}
console.log(new Vector(1,2,3));