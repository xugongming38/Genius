#include"demoscene1.h"

bool DemoScene1::init()
{
	//��ʼ������init
	if ( !Layer::init() )
    {
        return false;
    }
	
	autoCreatpopSprite();
	auto listener=MouseListener::create((MouseCallBack)&DemoScene1::handleMouse,this);
	EventDispatch::getInstance()->addListener(listener);


	return true;
}

 Scene *DemoScene1::createScene()
 {
    auto scene = Scene::create();

	//��������
	auto colorbg=ColorfulLayer::create(RGB(180,170,160));
    scene->addChild(colorbg);

    auto layer =DemoScene1:: create();

    scene->addChild(layer);

    // return the scene
    return scene;
 }

 void DemoScene1::update(float delta)
 {
	 //Vec2 v=sp->getPosition()+Vec2(1,1);
	// sp->setPosition(v);
 }

//�Զ��������η���
void DemoScene1::autoCreatpopSprite(){
		int color[6]={
			RGB(200,190,180),
			RGB(250,230,40),
			RGB(40,180,250),
			RGB(130,220,110),
			RGB(250,80,130),
			RGB(100,50,250)
		};
		int x=340;
		int y=80;
		//ÿ��pop�Ŀ��
		int lon=60;
		int num;
		//10*10
		for(int i=0;i<10;i++)
		for(int j=0;j<10;j++){
			{
				num= getRandomInt(5);
				PopSprite *pop =PopSprite::createPopSprite(num,i,j,color[num+1],Vec2(55,55),Vec2(x+60*j,y+i*60));
				addChild(pop);
				//����������
				popStarSprite[i][j]=pop;
		}
	}
}
 
void DemoScene1::handleMouse(MOUSEMSG m)
{
	if(!(m.uMsg==WM_LBUTTONUP||m.uMsg==WM_RBUTTONUP))
		 return;
	 Vec2 pos(m.x,m.y);

	PopSprite *pop=nullptr;
	Rect map=Rect(Vec2(340,80),600,600);
	//�ж��Ƿ���10*10������
	if(map.containPoint(pos))
	{
		Vec2 pure=pos-Vec2(340,80);
		int j=pure.getX()/60;
		int i=pure.getY()/60;
		pop=popStarSprite[i][j];


		//�ж��Ƿ�㵽��Ϸ����
		if(pop&&pop->getNum()!=-1)
		{
			//��ɾ�������
			poparr.len=0;
			checkPopUDLR(pop,i,j,poparr);
			if(poparr.size()>=2){
				checkPopISNEW();
			}
			if(poparr.len>0)
			{
				for(int i=0;i<poparr.len;i++)
					poparr.at(i)->setNum(-1);
			}
		}
	}

}

void DemoScene1::checkPopUDLR(PopSprite *pop,int i,int j,Array<PopSprite*> &poparr)
{
	bool isDoublePop =false;

	//�жϵ��λ�����ϵ���ͬ����
	int up=i;
	for(int yu =up-1;yu>=0;yu--){
		if(popStarSprite[yu][j]->getNum()==pop->getNum()){
			poparr.push_back(popStarSprite[yu][j]);
			isDoublePop=true;
	     }else
			break;
	}

	//�жϵ��λ�����µ���ͬ����
	int ud=i;
	for(int yd =ud+1;yd<10;yd++){
		if(popStarSprite[yd][j]->getNum()==pop->getNum()){
			poparr.push_back(popStarSprite[yd][j]);
			isDoublePop=true;
	     }else
			break;
	}

	//�жϵ��λ���������ͬ����
	int ul=j;
	for(int xl =ul-1;xl>=0;xl--){
		if(popStarSprite[i][xl]->getNum()==pop->getNum()){
			poparr.push_back(popStarSprite[i][xl]);
			isDoublePop=true;
	     }else
			break;
	}

	//�жϵ��λ�����ҵ���ͬ����
	int ur=j;
	for(int xr =ur+1;xr<10;xr++){
		if(popStarSprite[i][xr]->getNum()==pop->getNum()){
			poparr.push_back(popStarSprite[i][xr]);
			isDoublePop=true;
	     }else
			break;
	}
	//����
	if(isDoublePop)
		poparr.push_back(pop);
}
//ͨ����⵽�������ҵ�����ѭ���õ�ÿһ������������
void DemoScene1::checkPopISNEW(){
	//��ȡ�µ�����
	Array<PopSprite *> arrnew;
	Array<PopSprite *> arrnewTemp;

	for(int i=0;i<poparr.size();i++){
		PopSprite *pop =poparr.at(i);
		arrnew.len=0;
		checkPopUDLR(pop,pop->getI(),pop->getJ(),arrnew);
		for(int j=0;j<arrnew.size();j++){
			bool isSave=false;
			PopSprite *popnew =arrnew.at(j);
			for(int k=0;k<poparr.size();k++){
				PopSprite *popold =poparr.at(k);
				if(popnew->getI()==popold->getI()&&popnew->getJ()==popold->getJ()){
					isSave=true;
					break;
				}
			}
			if(!isSave){
				arrnewTemp.push_back(popnew);
			}

		}
	}
	if(arrnewTemp.size()>0){
		for(int i=0;i<arrnewTemp.size();i++)
			poparr.push_back(arrnewTemp.at(i));
		checkPopISNEW();
	}else{
		//ȫ����Ϊ-1
		for(int i=0;i<poparr.size();i++){
			PopSprite *p =poparr.at(i);
			p->setNum(-1);
		}
		//reDiessPopStar();
	}
}

//�ÿհײ����������
void DemoScene1::reDiessPopStar(){
	for(int i=0;i<10;i++){
		reDiessPopStarRun(i);
	}
}



void DemoScene1::reDiessPopStarRun(int x){
	//���ÿ�еĿո���
	int num=0;
	for(int k=0;k<10;k++ ){
		if(popStarSprite[x][k]->getNum()==-1)
			num++;
	}

	//�жϿո����Ƿ����1
	if(num>0){
		for(int y=0;y<10;y++){
		//�ж��Ƿ�ص��Լ�
			if(popStarSprite[x][y]->getNum()==-1){
				if(10-y>num){
					for(int i=y;i<10;i++){
						if(i+1==10)
							popStarSprite[x][i]->setNum(-1);
						else
							popStarSprite[x][i]->setNum(popStarSprite[x][i+1]->getNum());
					}
					reDiessPopStarRun(x);
				}
			}
		}
	}
}