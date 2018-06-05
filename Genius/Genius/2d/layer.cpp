#include"Layer.h"

 Layer* Layer::create()
 {
	 Layer *layer =new Layer();
	 if(layer->init())
	 {
		//加入自释放池
		layer->autorelease();
		return layer;
	 }
	 return nullptr;
 }
 Layer::Layer()
 {
	
 }
 bool Layer::init()
 {
	 //初始化孩子节点
	 return true;
 }

