#include "editor.h"
#include <iostream>
using namespace std;


Editor::Editor(QWidget *parent) :  QsciScintilla(parent)
{

    lexer = new QsciLexerCPP;
    this->setLexer(lexer);


    api = new QsciAPIs(lexer);

    api->prepare();

    this->setAutoCompletionThreshold(1);
    this->setAutoCompletionSource(QsciScintilla::AcsAll);
}


Editor::Editor(QString &text) : Editor()
{
    setText(text);
}


void Editor::setText(QString &text)
{
    QsciScintilla::setText(text);
}


Editor::~Editor()
{
    cout << "Destruindo aba" << endl;
    delete lexer;
    delete api;
}
