#ifndef OCR_H
#define OCR_H

#include "qstring.h"
#include <tesseract/baseapi.h>
#include <leptonica/allheaders.h>
#include <QImage>
#include <QFile>

class OCR
{
    public:
        OCR();
        bool Init();
        QString ProcessFile(QString f);

    private:
        tesseract::TessBaseAPI *mp_api;
};

#endif // OCR_H
