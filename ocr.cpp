#include <QDebug>

#include "ocr.h"


OCR::OCR() : mp_api(0)
{
}

bool OCR::Init()
{
    mp_api = new tesseract::TessBaseAPI();
    if (mp_api->Init(NULL, "eng"))
        return false;
    else
        return true;
}

QString OCR::ProcessFile(QString f)
{
    char *outText;
    Pix *image = pixRead(f.toStdString().c_str());
    mp_api->SetImage(image);
    outText = mp_api->GetUTF8Text();
    QString out = QString(outText);
    mp_api->End();
    delete [] outText;
    pixDestroy(&image);
    return out;
}
