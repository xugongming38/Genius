#include"Layer.h"

 Layer* Layer::create()
 {
	 Layer *layer =new Layer();
	 if(layer->init())
	 {
		//�������ͷų�
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
	 //��ʼ�����ӽڵ�
	 return true;
 }

