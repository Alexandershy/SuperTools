#include "_chatbubble_.h"

ChatBubble::ChatBubble(QWidget *parent,QString message)
    : QTextEdit(parent)
{
    Parent = parent;
    Init();
    setHtml(message);
    Adjustwidth();
}

ChatBubble::~ChatBubble()
{

}

void ChatBubble::Init()
{
    setReadOnly(true);
    setAlignment(Qt::AlignCenter);
    QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
    sizePolicy.setHorizontalStretch(0);
    sizePolicy.setVerticalStretch(0);
    sizePolicy.setHeightForWidth(this->sizePolicy().hasHeightForWidth());
    setSizePolicy(sizePolicy);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setMinimumWidth(20);
    setMinimumHeight(20);
    setStyleSheet("QTextEdit{background-color:rgb(169, 189, 255);margin:0px;}");
}

void ChatBubble::Adjustwidth()
{
    int maxwidth = 2 * Parent->width() / 3;
    QTextDocument *document = this->document();
    QFontMetrics fontmetrics(document->defaultFont());
    int width = fontmetrics.boundingRect(this->toPlainText()).width() + 20;
    if(maxwidth < width)
    {
        setMinimumWidth(maxwidth);
    }
    else
    {
        setMinimumWidth(width);
    }
}

/*  adjust bubble width api;*/

void ChatBubble::Adjustheight()
{
    int height = verticalScrollBar()->maximum() - verticalScrollBar()->minimum() + verticalScrollBar()->pageStep();
    setMinimumHeight(height);
}

/*  adjust bubble height api;*/
