#ifndef __VEC2_H__
#define __VEC2_H__

// 1.Vec2点类
//ctrl+h 替换
class Vec2
{
private:
	int x,y;
public:
	Vec2(int x=0,int y=0){this->x=x;this->y=y;}
	void setX(int x){this->x=x;}
	void setY(int y){this->y=y;}
	void setXY(int x,int y){this->x=x;this->y=y;}
	int getX()const{return x;}
	int getY()const{return y;}
	Vec2 getPosition(){ return *this;}

	//基本操作
	Vec2& operator=(Vec2 &p);//赋值
	Vec2& operator=(int xy);//赋值
	bool operator==(Vec2 &p);//比较
	friend Vec2 operator+(const Vec2 &l,const Vec2 &r);//加法
	friend Vec2 operator-(const Vec2 &l,const Vec2 &r);//减法
	friend Vec2 operator*(const Vec2 &p,const double &scale);//乘法(使用double类型)
	friend Vec2 operator*(const double &scale,const Vec2 &p);//乘法(使用double类型)
	friend Vec2 operator/(const Vec2 &p,const double &scale);//乘法(使用double类型)
};

//返回两个点的距离的平方
int PointDistance(Vec2 v1,Vec2 v2);
#endif