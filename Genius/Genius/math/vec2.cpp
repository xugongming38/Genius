#include"vec2.h"

// 1.Vec2点类
Vec2 & Vec2::operator=(Vec2 &p)//赋值
{
	this->x=p.getX();
	this->y=p.getY();
	return *this;

}
Vec2 & Vec2::operator=(int xy)//赋值
{
	this->x=xy;
	this->y=xy;
	return *this;

}
bool Vec2::operator==(Vec2 &p)//比较
{
	return x==p.getX()&&y==p.getY();
}

 Vec2 operator+(const Vec2 &l,const Vec2 &r)//加法
 {
	 return Vec2(l.getX()+r.getX(),l.getY()+r.getY());
 }
 Vec2 operator-(const Vec2 &l,const Vec2 &r)//减法
 {
	 return Vec2(l.getX()-r.getX(),l.getY()-r.getY());
 }
 Vec2 operator*(const Vec2 &p,const double &scale)//乘法(使用double类型)
 {
	 return Vec2((int)p.getX()*scale,(int)p.getY()*scale);
 }
 Vec2 operator*(const double &scale,const Vec2 &p)//乘法(使用double类型)
 {
	 return Vec2((int)p.getX()*scale,(int)p.getY()*scale);
 }

  Vec2 operator/(const Vec2 &p,const double &scale)//乘法(使用double类型)
  {
	  return Vec2((int)p.getX()*scale,(int)p.getY()*scale);
  }

  //返回两个点的距离的平方
int PointDistance(Vec2 v1,Vec2 v2)
{
	int a=v1.getX()-v2.getX();
	int b=v1.getY()-v2.getY();
	return a*a+b*b;
}