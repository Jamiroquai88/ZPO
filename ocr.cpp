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
    delete [] outText;
    pixDestroy(&image);

    //delete created help image
    if(f == "ultra_super_unikatni_nazev_tmp_souboru.png") {
        QFile file(f);
        file.remove();
    }
    return out;
}
