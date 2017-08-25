#include "ocr.h"


int TessRecognizePix (Pix *image,
                      const char *lang, char *&outText, const char *datapath,
                      char *error_code, char *error_message) {

  tesseract::TessBaseAPI *api = new tesseract::TessBaseAPI();

  int failed = api->Init(datapath, lang);
  if (failed) {
    const char *code = "TESSER_INIT_ERROR";
    const char *message = "Could not initialize tesseract.";
    strcpy(error_code, code);
    strcpy(error_message, message);

    return failed;
  }

  api->SetImage(image);

  // Get OCR result
  outText = api->GetUTF8Text();

  // Destroy used object and release memory
  api->End();

  return 0;
}
