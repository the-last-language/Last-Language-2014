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

	 auto sprite1 = Sprite::create("dialog/bg.png");
	
	 int dialog_num = UserDefault::getInstance()->getIntegerForKey("Dialog");
 	auto label = Label::createWithTTF(UTF8("Object TEST.\n그냥 일반적인 컴퓨터.\n지금은 고장남.\n아마 접속콘솔로 쓰일듯."),"fonts/GodoB.ttf",30);

	switch(dialog_num)
	{
	case 3://game1, bg0, 칩을 주워라.
		sprite1 = Sprite::create("dialog/game1_bg0.png");
		label = Label::createWithTTF(UTF8("몇개의 칩으로 보이는 물체를 주웠다.\n네모 다섯개가 연결되어 있다.\n각 네모에는 글자가 적혀 있다.\n[단어칩 2개를 획득하였습니다.]"),"fonts/GodoB.ttf",30);
		break;
	case 4://game1, bg0, 전선을 주워라
		sprite1 = Sprite::create("dialog/game1_bg0.png");
		label = Label::createWithTTF(UTF8("낡은 전선을 주웠다.\n분명 어딘가에 쓸모는 있을 것이다.\n[전선 2개를 주웠습니다.]"),"fonts/GodoB.ttf",30);
		break;//여기까지 GameScene1에 할당된 대화창
	case 5://room0202 칩을 주워라
		sprite1 = Sprite::create("dialog/game1_bg2_1.png");
		label = Label::createWithTTF(UTF8("몇개의 칩으로 보이는 물체를 주웠다.\n역시 이것도 글자가 적혀 있다.\n무엇에 쓰일까?\n[단어칩 2개를 획득하였습니다.]"),"fonts/GodoB.ttf",30);
		break;
	case 6://room202 전선을 주워라.
		sprite1 = Sprite::create("dialog/game1_bg2_1.png");
		label = Label::createWithTTF(UTF8("침대에서 잠깐 쉬려고 했는데 뭔가 거슬린다.\n줍고 나서 보니 전선이다.\n[전선 3개를 주웠습니다.]"),"fonts/GodoB.ttf",30);
		break;
	case 7://room203 전선
		sprite1 = Sprite::create("dialog/game1_bg2_2.png");
		label = Label::createWithTTF(UTF8("관물대는 텅 비어있다.\n근데, 내가 왜 이걸 뒤지는거지?\n여기서 나가는게 우선인데?\n그런 생각하면서 빠져나가려는 찰나에\n옷의 끝자락에 전선 한개가 걸려 있는것을 보았다.\n[전선 1개를 주웠습니다.]"),"fonts/GodoB.ttf",30);
		break;
	case 8://room203 칩
		sprite1 = Sprite::create("dialog/game1_bg2_2.png");
		label = Label::createWithTTF(UTF8("총에 칩이라...\n이 총은 전자식으로 작동되는 총이 아닌걸로 알고 있는데.\n칩이 왜 있지?\n[단어칩 2개를 획득하였습니다.]"),"fonts/GodoB.ttf",30);
		break;
	case 9://room401칩
		sprite1 = Sprite::create("dialog/game1_bg4_1.png");
		label = Label::createWithTTF(UTF8("우연히 열어본 서랍속에\n칩들이 들어있다.\n분명 어딘가에 쓰일거야.\n계속 모아보자.\n[단어칩 2개를 획득하였습니다.]"),"fonts/GodoB.ttf",30);
		break;
	case 10://room401전선
		sprite1 = Sprite::create("dialog/game1_bg4_1.png");
		label = Label::createWithTTF(UTF8("우연히 열어본 서랍속에\n전선들이 들어있다.\n전선을 계속 주워야 한다고 계속 판단한다.\n왜 그렇게 생각하는지 잘 모르겠다.\n[전선 4개를 주웠습니다.]"),"fonts/GodoB.ttf",30);
		break;
	case 11://room402스크린
		sprite1 = Sprite::create("dialog/game1_bg4_2.png");
		label = Label::createWithTTF(UTF8("큰 스크린에 희미하게 글자들이 보인다.\n '후얄발두칼붸퀘떠뭬거훼.....'같은 이상한 것이 쓰여있다.\n이상한 글자 중에서 내가 읽을 수 있는 것들이 있다.\n대략 조합해 보자면 이렇다.\n\n'금세'는 '금시에'의 줄임말이다.\n'몇일'이라는 단어는 없다. '며칠'로 써야한다.\n모든 장소를 꼼꼼히 놓치는 부분 없이 잘 살펴보아야 한다.\n\n이상한 글자속에 섞여 있는 읽을 수 있는 문장이지만\n뜻을 가진다는 것만 알지 무슨 뜻인지 모르겠다."),"fonts/GodoB.ttf",30);
		break;
	case 12://bg5 쓰레기통
		sprite1 = Sprite::create("dialog/game1_bg5.png");
		label = Label::createWithTTF(UTF8("쓰레기통을 뒤져야 한다고 느꼈다.\n즉시 본능대로 하니 역시나 칩 몇개와 전선 몇 개가 보였다.\n일단 가져가보자\n[전선 3개와 단어칩 2개를 획득하였습니다.]"),"fonts/GodoB.ttf",30);
		break;
	case 13://bg5 환풍구
		sprite1 = Sprite::create("dialog/game1_bg5_1.png");
		label = Label::createWithTTF(UTF8("환풍구에 또다른 길이 있을 것이라고 기대했지만 아쉽게도 막혀있다.\n다만 쪽지가 놓여 있다.\n근데 읽을 수 없다.\n다만 그 중에서 알아 먹을 수 있는걸 보자면\n\n..............\n\n단일어... 합성어... 파생어...\n파생어 : 뜻을 나타내는 형태소에 접사가 붙는다.\n합성어 : 둘 이상의 형태소끼리 만난다.\n단일어 : 형태소로만 이루어져 있다.\n\n..............\n\n읽을 수는 있지만 무슨 말인지 모르겠다."),"fonts/GodoB.ttf",30);
		break;
	case 14://room501 단말기
		sprite1 = Sprite::create("dialog/game1_bg5_2.png");
		label = Label::createWithTTF(UTF8("여기는 꼭 전자회로 실험실 같다.\n전자기판들이 널부러져 있다.\n저기 그나마 정상적인 기판이 보인다.\n조금만 손 쓰면 뭔가 볼 수 있을 것이다."),"fonts/GodoB.ttf",30);
		break;
	case 15://room501전선
		sprite1 = Sprite::create("dialog/game1_bg5_2.png");
		label = Label::createWithTTF(UTF8("아마도 지금 이 방에서 전선을 써야만 할 것 같다.\n조금 챙겨가자/\n[전선 5개를 주웠습니다.]"),"fonts/GodoB.ttf",30);
		break;
	case 16://bg4 잠김
		sprite1 = Sprite::create("dialog/game1_bg4.png");
		label = Label::createWithTTF(UTF8("아직 여긴 잠겨있다.\n여는 방법이 있을지도 모른다."),"fonts/GodoB.ttf",30);
		break;
	case 17://room502 칩
		sprite1 = Sprite::create("dialog/game1_bg5_3.png");
		label = Label::createWithTTF(UTF8("칩들이 설마...\n어디서 많이 들어본 합성어, 단일어, 파생어와 관련되어 있는 것은 아닐까?\n[단어칩 2개를 획득하였습니다.]"),"fonts/GodoB.ttf",30);
		break;
	case 18://room502 대화
		sprite1 = Sprite::create("dialog/game1_bg5_3.png");
		label = Label::createWithTTF(UTF8("종이에 쓰인 글은 빠진거 없이 잘 챙겨라는 뜻 같다.\n사물함은 모두 열어보자. 놓치는 부분 없이 다 찾아보자.\n꼼꼼이...아니지 꼼꼼히 살펴보자.\n"),"fonts/GodoB.ttf",30);
		break;
	case 19://room502 칩
		sprite1 = Sprite::create("dialog/game1_bg5_3.png");
		label = Label::createWithTTF(UTF8("이것이 열쇠인가??\n[단어칩 2개를 획득하였습니다.]"),"fonts/GodoB.ttf",30);
		break;
	case 20://엘리베이터 중단
		sprite1 = Sprite::create("dialog/game1_bg3.png");
		label = Label::createWithTTF(UTF8("\n\n\n\n\n\n\n엘리베이터가 작동을 하지 않는다."),"fonts/GodoB.ttf",30);
		break;
	default:
		sprite1 = Sprite::create("dialog/bg.png");
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
                                           "CloseNormal.png",
                                           "CloseSelected.png",
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
