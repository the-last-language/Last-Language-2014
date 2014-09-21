#include "Dialog.h"
#include "MenuScene.h"
#include "KoreanUTF8.h"

USING_NS_CC;

Scene* Dialog::createScene()
{
    auto scene = Scene::create();
    
    auto layer = Dialog::create();

    scene->addChild(layer);

    return scene;
}


bool Dialog::init()
{
    if ( !Layer::init() )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

	 auto sprite1 = Sprite::create("data/dialog/bg.png");
	
	 int dialog_num = UserDefault::getInstance()->getIntegerForKey("Dialog");
 	auto label = Label::createWithTTF(UTF8("Object TEST.\n그냥 일반적인 컴퓨터.\n지금은 고장남.\n아마 접속콘솔로 쓰일듯."),"data/fonts/GodoB.ttf",30);

	switch(dialog_num)
	{
	case 3://game1, bg0, 칩을 주워라.
		sprite1 = Sprite::create("data/dialog/game1_bg0.png");
        label = Label::createWithTTF(UTF8("특정한 전자기기에 부착할 수 있도록 만들어진 칩 같은 것들을 주웠다.\n네모난 칩 5개가 단자로 연결되어 있다.\n각 칩 위에는 글자가 적혀 있다.\n[단어칩 2개를 획득하였습니다.]"),"data/fonts/GodoB.ttf",30);
		break;
	case 4://game1, bg0, 전선을 주워라
		sprite1 = Sprite::create("data/dialog/game1_bg0.png");
        label = Label::createWithTTF(UTF8("낡은 전선을 주웠다.\n분명 어딘가에 쓸모는 있을 것이다.\n[전선 2개를 주웠습니다.]"),"data/fonts/GodoB.ttf",30);
		break;//여기까지 GameScene1에 할당된 대화창
	case 5://room0202 칩을 주워라
		sprite1 = Sprite::create("data/dialog/game1_bg2_1.png");
        label = Label::createWithTTF(UTF8("아까 봤던 것과 똑같이 생긴 칩들을 또 주웠다.\n누군가가 이것들을 여기저기 흩뿌린 모양이다.\n역시 여기에도 글자가 적혀 있다.\n대체 무엇에 쓰이는 물건일까?\n[단어칩 2개를 획득하였습니다.]"),"data/fonts/GodoB.ttf",30);
		break;
	case 6://room202 전선을 주워라.
		sprite1 = Sprite::create("data/dialog/game1_bg2_1.png");
        label = Label::createWithTTF(UTF8("침대에서 잠깐 누워서 쉬려고 했는데 등에 걸리는 게 있다.\n주워보니 전선이다.\n[전선 3개를 주웠습니다.]"),"data/fonts/GodoB.ttf",30);
		break;
	case 7://room203 전선
		sprite1 = Sprite::create("data/dialog/game1_bg2_2.png");
        label = Label::createWithTTF(UTF8("관물대에는 전투복 한 벌만 걸려있다.\n잠깐...근데 내가 왜 남의 관물대를 뒤지는 거지?\n일단 여기서 빠져나가는게 우선일텐데?\n하면서 관물대를 닫으려는 찰나에\n걸어놓은 전투복 상의 수첩 주머니 위로 살짝 삐져나온 전선 하나가 보였다.\n[전선 1개를 주웠습니다.]"),"data/fonts/GodoB.ttf",30);
		break;
	case 8://room203 칩
		sprite1 = Sprite::create("data/dialog/game1_bg2_2.png");
        label = Label::createWithTTF(UTF8("총에 칩이라...\n이 총은 전자식으로 작동되는 총이 아닌걸로 알고 있는데.\n칩이 왜 있지?\n[단어칩 2개를 획득하였습니다.]"),"data/fonts/GodoB.ttf",30);
		break;
	case 9://room401칩
		sprite1 = Sprite::create("data/dialog/game1_bg4_1.png");
		label = Label::createWithTTF(UTF8("우연히 열어본 서랍속에\n칩들이 들어있다.\n분명 어딘가에 쓰일거야.\n계속 모아보자.\n[단어칩 2개를 획득하였습니다.]"),"data/fonts/GodoB.ttf",30);
		break;
	case 10://room401전선
		sprite1 = Sprite::create("data/dialog/game1_bg4_1.png");
        label = Label::createWithTTF(UTF8("우연히 열어본 서랍속에\n전선들이 들어있다.\n전선을 계속 주워야 한다는 직감이 들었다.\n이유는 없다. 다만 여기서 나가고 싶다.\n[전선 4개를 주웠습니다.]"),"data/fonts/GodoB.ttf",30);
		break;
	case 11://room402스크린
		sprite1 = Sprite::create("data/dialog/game1_bg4_2.png");
        label = Label::createWithTTF(UTF8("큰 스크린에 희미하게 글자들이 보인다.\n'후얄발두칼붸퀘떠뭬거훼.....'같은 이상한 것이 쓰여있다.\n읽던 도중 이상한 글자들 사이에서 간혹 내가 읽을 수 있는 한국어가 있었다.\n대략 조합해 보자면 이렇다.\n\n'금세'는 '금시에'의 줄임말이다.\n'몇일'이라는 단어는 없다. '며칠'로 써야한다.\n분명 누군가가 어떤 정보를 숨기려 한 모양이다.\n\n이상한 글자들 속에 섞여 있는 단어들을 계속 조합하니 뭔가 말이 되는 것 같다.\n출구만 찾으면 나갈거라 생각했는데 생각이 바꼈다.\n하나 하나 꼼꼼하게 단서들과 숨겨진 정보를 찾아야 한다."),"data/fonts/GodoB.ttf",28);
		break;
	case 12://bg5 쓰레기통
		sprite1 = Sprite::create("data/dialog/game1_bg5.png");
        label = Label::createWithTTF(UTF8("쓰레기통을 뒤져야 한다고 느꼈다.\n즉시 본능대로 하니 역시나 칩 몇개와 전선 몇 개가 보였다.\n일단 가져가보자\n[전선 3개와 단어칩 2개를 획득하였습니다.]"),"data/fonts/GodoB.ttf",30);
		break;
	case 13://bg5 환풍구
		sprite1 = Sprite::create("data/dialog/game1_bg5_1.png");
        label = Label::createWithTTF(UTF8("환풍구에 또다른 길이 있을 것이라고 기대했지만 아쉽게도 막혀있다.\n다만 쪽지가 놓여 있다.\n쪽지가 일부 찢어져 있다.\n거의 읽을 수 없지만 남은 글자 중에서 알아 먹을 수 있는걸 보니\n\n..............\n\n단일어... 합성어... 파생어...\n단일어 : 하나의 형태소로 이루어진 단어이다......나무\n합성어 : 둘 이상의 어근이 결합되어 만들어진 단어이다....\n사과나무 = 사과 + 나무\n파생어 : 어근과 접사가 결합되어서 이루어진 단어이다...나무꾼 = 나무 + -꾼\n*어근 : 한 단어에서 더 이상 나눌 수 없이 의미의 중심이 되는 것..\n*접사 : 어근의 앞 뒤에 붙어서 의미를 더해주거나 품사를 바꿈..\n\n\n..............\n\n읽을 수는 있지만 무슨 말인지 모르겠다."),"data/fonts/GodoB.ttf",28);
		break;
	case 14://room501 단말기
		sprite1 = Sprite::create("data/dialog/game1_bg5_2.png");
        label = Label::createWithTTF(UTF8("여기는 꼭 전자회로 실험실 같다.\n지금도 작동이 되는 걸까?\n전자기판들이 이리저리 널부러져 있다.\n저기 그나마 정상적인 기판이 보인다.\n저것을 조금만 손 쓰면 뭔가 볼 수 있을 것이다."),"data/fonts/GodoB.ttf",30);
		break;
	case 15://room501전선
		sprite1 = Sprite::create("data/dialog/game1_bg5_2.png");
        label = Label::createWithTTF(UTF8("아마도 지금 이 방에서 전선을 써야만 할 것 같다.\n조금 챙겨가자.\n[전선 5개를 주웠습니다.]"),"data/fonts/GodoB.ttf",30);
		break;
	case 16://bg4 잠김
		sprite1 = Sprite::create("data/dialog/game1_bg4.png");
        label = Label::createWithTTF(UTF8("아직 이 문은 잠겨있다.\n여는 방법이 있을지도 모른다."),"data/fonts/GodoB.ttf",30);
		break;
	case 17://room502 칩
		sprite1 = Sprite::create("data/dialog/game1_bg5_3.png");
        label = Label::createWithTTF(UTF8("내가 모은 칩들이 설마......\n아까 쪽지에서 본 합성어, 단일어, 파생어와 관련되어 있는 것은 아닐까?\n[단어칩 2개를 획득하였습니다.]"),"data/fonts/GodoB.ttf",30);
		break;
	case 18://room502 대화
		sprite1 = Sprite::create("data/dialog/game1_bg5_3.png");
        label = Label::createWithTTF(UTF8("종이에 써진 글이 의미하는 바는 물품들을 빠짐없이 잘 챙겨라는 뜻 같다.\n사물함은 모두 열어보자. 놓치는 부분 없이 다 찾아보자.\n꼼꼼이...아니지 꼼꼼히 살펴보자.\n"),"data/fonts/GodoB.ttf",30);
		break;
	case 19://room502 칩
		sprite1 = Sprite::create("data/dialog/game1_bg5_3.png");
		label = Label::createWithTTF(UTF8("이것이 열쇠인가??\n[단어칩 2개를 획득하였습니다.]"),"data/fonts/GodoB.ttf",30);
		break;
	case 20://엘리베이터 중단
		sprite1 = Sprite::create("data/dialog/game1_bg3.png");
		label = Label::createWithTTF(UTF8("\n\n\n\n\n\n\n엘리베이터가 작동을 하지 않는다."),"data/fonts/GodoB.ttf",30);
		break;
	case 21://엘리베이터 중단
		sprite1 = Sprite::create("data/dialog/game1_bg4_3.png");
		label = Label::createWithTTF(UTF8("지금은 작동이 되지 않는 것 같다.\n"),"data/fonts/GodoB.ttf",30);
		break;
	case 22://엘리베이터 중단
		sprite1 = Sprite::create("data/dialog/game1_bg4_3.png");
		label = Label::createWithTTF(UTF8("복잡한 글자들 투성이다.\n그 중간에 볼 수 있는 수많은 '성공'과 '실패'들...\n무엇을 했던 것일까?\n그리고 왜 그들은 사라졌는가?\n이때까지 본 것에 의하면 적어도 그들은 여기에 없다."),"data/fonts/GodoB.ttf",30);
		break;
	default:
		sprite1 = Sprite::create("data/dialog/bg.png");
		break;
	}

	sprite1->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));

	this->addChild(sprite1, 0);

	label->setPosition(Point(480,320));
	this->addChild(label);
   
	initCancel();
    
    return true;
}

void Dialog::initCancel()
{
	 Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
	auto closeItem = MenuItemImage::create(
                                           "data/CloseNormal.png",
                                           "data/CloseSelected.png",
										   CC_CALLBACK_1(Dialog::menuCloseCallback, this));
    
	closeItem->setPosition(Vec2(origin.x + visibleSize.width - closeItem->getContentSize().width/2 ,
                                origin.y + closeItem->getContentSize().height/2));
	
    auto menu = Menu::create(closeItem, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);
}


void Dialog::menuCloseCallback(Ref* pSender)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WP8) || (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT)
	MessageBox("You pressed the close button. Windows Store Apps do not implement a close button.","Alert");
    return;
#endif

    //Director::getInstance()->end();
	Director::getInstance()->popScene();
	//Director::getInstance()->replaceScene(MenuScene::createScene());
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
