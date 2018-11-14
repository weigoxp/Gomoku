#pragma once


class BottonUI
{

public:
    BottonUI();
    void Start();
    void Stop();
    static AngelUIHandle _choiceBox;
    static AngelUIHandle _choiceBox2;
 //   static TextActor* _output;

private:
    AngelUIHandle _button;

    //int i;

};
