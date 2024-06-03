#include "DxLib.h"//Dxライブラリーをインクルード(読み込み)

int WinMain(HINSTANCE, HINSTANCE, LPSTR, int)//Windowsのメインで動かす
{
    //基本設計
    ChangeWindowMode(TRUE);//Windowsの画面をアクティブにする
    DxLib_Init();//DxLibの初期化
    SetDrawScreen(DX_SCREEN_BACK);//画面の背景は黒
    SetGraphMode(800, 600, 32);//画面の大きさ

    //DxLibの初期化処理
    if (DxLib_Init() == -1)
    {
     //エラーが起きたら直ちに終了
        return -1;
    }
    //円の初期位置
    int circleX = 200;
    int circleY = 150;

    int stringX = 10;
    int stringY = 15;
    int stringX1 = 10;
    int stringY1 = 45;

    int mouseX = 0;
    int mouseY = 0;
    //円の色指定
    int circleColor = GetColor(0, 0, 255);
    //文字の色指定
    int StringColor = GetColor(255, 255, 255);
    int StringColor2 = GetColor(255, 0, 0);


    //ゲームループ
    while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0)
    {
        //画面の初期化
        ClearDrawScreen();

        //文字の大きさの指定
        SetFontSize(32);

        //画面に文字を表示
        DrawFormatString(stringX, stringY, StringColor, "Mouse X:%d Y:%d", mouseX, mouseY);

        //画面に円を描画させる
        DrawCircle(circleX, circleY, 30, circleColor, TRUE);

        //マウスの座標を取得
        GetMousePoint(&mouseX ,&mouseY);

        //マウスがクリックされたら
        if ((GetMouseInput() & MOUSE_INPUT_LEFT))
        {
            SetFontSize(30);
            DrawString(stringX1, stringY1, "Hit!", StringColor2);
        }
        //テンキーを押したら上・下・右・左に動く
        //上
        if (CheckHitKey(KEY_INPUT_UP))
        {
            if (circleY <= 40)
            {
                circleY += 3;
            }
            else
            {
                circleY -= 3;
            }
        }
        //下
        if (CheckHitKey(KEY_INPUT_DOWN))
        {
            if (circleY >= 560)
            {
                circleY -= 3;
            }
            else
            {
                circleY += 3;
            }
        }
        //右
        if (CheckHitKey(KEY_INPUT_RIGHT))
        {
            if (circleX >= 760)
            {
                circleX -= 3;
            }
            else
            {
                circleX += 3;
            }
        }
        //左
        if (CheckHitKey(KEY_INPUT_LEFT))
        {
            if (circleX <= 40)
            {
                circleX += 3;
            }
            else
            {
                circleX -= 3;
            }
        }
        

        if (CheckHitKey(KEY_INPUT_H)) {
            DrawCircle(circleX, circleY, 30, GetColor(0, 255, 255), TRUE);
        }
        //円のX座標に動きをつける
       /* circleX += 60;
        circleY += 45;
        if (circleX >= 800)
        {
            circleX = 0;
            circleY = 0;
        }*/
        //裏画面の内容を表画面に反映させる
        ScreenFlip();
    }

    //画面に円を描画させる
    DrawCircle(320, 240, 30, GetColor(0, 0, 255), TRUE);

    

    //キー入力待ち
    WaitKey();

    //Dxlib使用の終了処理
    DxLib_End();

    //ソースの終了
    return 0;
}