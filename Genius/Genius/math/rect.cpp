#include"rect.h"
#include"../base/base.h"
Rect::Rect(Vec2 p,int w,int h)
{
	point =p;
	width=w;
	height=h;
}

bool Rect::containPoint(Vec2 p)
{
	//cout<<p.getX()<<" "<<p.getY()<<endl;
	//cout<<point.getX()<<" "<<point.getY()<<endl;
	if(p.getX()>point.getX()&&p.getX()<point.getX()+width)
		if(p.getY()>point.getY()&&p.getY()<point.getY()+height)
			return true;

	return false;
}