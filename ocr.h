#ifndef OCR_H
#define OCR_H

#include "qstring.h"
#include <tesseract/baseapi.h>
#include <leptonica/allheaders.h>

class OCR
{
public:
    OCR();
    QString ProcessFile(QString f);
};

#endif // OCR_H
