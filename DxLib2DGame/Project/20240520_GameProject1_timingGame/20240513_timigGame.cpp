#include"DxLib.h"
#define _USE_MATH_DEFINES
#include<stdio.h>
#include<math.h>

//�萔
#define SCREEN_X 800
#define SCREEN_Y 600
#define CIRCLE_POS_X 400
#define CIRCLE_POS_Y 300
#define CIRCLE_RADIUS_START 10
#define CIRCLE_RADIUS_MAX 200

//�ϐ�
typedef struct circle
{
    int posX;
    int posY;
    int radius;
    double area;
}circle;

//�Q�[���t���O
bool enterPressedLastFrame = false; //�G���^�[�L�[�������ꂽ���ǂ����̃t���O
bool gameStartFlag = false;          //�Q�[���J�n�t���O
bool circleGenerationFlag = true;   //�~�̐����t���O
bool gameEndFlag = true;            //�Q�[���I���t���O

//�Q�[���J�E���g
int enterPressCount;

//�\���̂�ϐ��ɂ���
circle Circle;

//�~�̍ő�ʐ�
double circleAreaMax = M_PI * CIRCLE_RADIUS_MAX * CIRCLE_RADIUS_MAX;

//���C���֐�
int WinMain(HINSTANCE, HINSTANCE, LPSTR, int)//Windows�̃��C���œ�����
{
 //------------------------------//
 //�@��{�ݒ�
 //------------------------------//
    ChangeWindowMode(TRUE);         //Windows�̉�ʂ��A�N�e�B�u�ɂ���
    DxLib_Init();                   //DxLib�̏�����
    SetMainWindowText("�^�C�s���O�Q�[��");
    SetDrawScreen(DX_SCREEN_BACK);  //��ʂ̔w�i�͍�
    SetGraphMode(SCREEN_X, SCREEN_Y, 32);     //��ʂ̑傫��

    //DxLib�̏���������
    if (DxLib_Init() == -1)
    {
        //�G���[���N�����璼���ɏI��
        return -1;
    }

    //�F�w��
    int CircleColer = GetColor(128, 128, 128);
    
    //�~�̏����ʒu
    Circle.posX = CIRCLE_POS_X;
    Circle.posY = CIRCLE_POS_Y;

    //�~�̑傫���ݒ�
    Circle.radius = CIRCLE_RADIUS_START;

 //------------------------------//
 //�@�Q�[�����[�v
 //------------------------------//
    while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0 && ClearDrawScreen() == 0)
    {
        //��ʂ̏�����
        ClearDrawScreen();

        if (CheckHitKey(KEY_INPUT_RETURN) && !enterPressedLastFrame)
        {
            //�Q�[���̊J�n
            gameStartFlag = !gameStartFlag;
        }

        //�G���^�[�L�[�������ꂽ�����L��������
        enterPressedLastFrame = CheckHitKey(KEY_INPUT_RETURN);

        if (gameStartFlag)
        {
            if (circleGenerationFlag)
            {
                //���a��5�����₷
                Circle.radius += 5;
                //���a���ő�l�ɂȂ����Ƃ��t���O��ϊ�
                if (Circle.radius >= CIRCLE_RADIUS_MAX)
                {
                    circleGenerationFlag = false;
                }
            }
            else
            {
                 Circle.radius -= 5;
                    
                if (Circle.radius <= CIRCLE_RADIUS_START)
                {
                     circleGenerationFlag = false;
                }

            }
        

        }

        //��ʂɉ~��`�悳����
        DrawCircle(Circle.posX, Circle.posY, Circle.radius, CircleColer);

        //����ʂ̓��e��\��ʂɔ��f������
        ScreenFlip();

        //60FPS�ɒ���
        WaitTimer(1000 / 60);
    }

    //Dxlib�g�p�̏I������
    DxLib_End();

    return 0;

}


