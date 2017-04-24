#include <QDebug>

#include "ocr.h"


OCR::OCR()
{

}

QString OCR::ProcessFile(QString f)
{
    char *outText;

    tesseract::TessBaseAPI *api = new tesseract::TessBaseAPI();
    if (api->Init(NULL, "eng"))
        return "";

    Pix *image = pixRead(f.toStdString().c_str());
    api->SetImage(image);
    outText = api->GetUTF8Text();
    printf("OCR output:\n%s", outText);
    QString out = QString(outText);
    api->End();
    delete [] outText;
    pixDestroy(&image);
    return out;
}
