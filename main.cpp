#include <cstdio>
#include <fstream>
#include <iostream>
#include <GraphicsMagick/Magick++.h>
#include <string>
#include <tesseract/baseapi.h>
#include <leptonica/allheaders.h>
#include <regex>
#include "include/CLI11.hpp"

using namespace std;
using namespace Magick;

int convert(int argc , char** argv , string pdf_file , string image_file , string output_file){
    /* cout << pdf_file.length() << " " << image_file.length() << endl; */ 
    if (pdf_file.length() > 0 && image_file.length() == 0){
        InitializeMagick(*argv);
   
        Image image;
        image.density("300");
        image.read(pdf_file);
        image.write(pdf_file + ".png");
    }

        
    tesseract::TessBaseAPI *ocr = new tesseract::TessBaseAPI();
    if (ocr->Init(NULL , "eng")){
        cerr << "Error : Could Not Initialize Tesseract!" << endl;
        exit(1);
    }

    ocr->SetPageSegMode(tesseract::PSM_AUTO);
    
    Pix *ocr_image;
    string _file;
    if (image_file.length() > 0){
      ocr_image = pixRead(image_file.c_str());
        _file = image_file;
    }else if (pdf_file.length() > 0){
        string pdfimage = pdf_file + ".png";
        ocr_image = pixRead(pdfimage.c_str());
        _file = pdfimage;
    }

    ocr->SetImage(ocr_image);
    string outtext = ocr->GetUTF8Text();
    
    regex r("(\\w+)(\\.|_)?(\\w*)@(\\w+)(\\.(\\w+))+");

    sregex_iterator next(outtext.begin() , outtext.end() , r);
    sregex_iterator end;
    ofstream output(output_file);
    while (next != end){
      smatch match = *next;
      output << match.str() << endl;
      next++;
    }
    output.close();

    ocr->End();
    delete ocr;
    remove(_file.c_str());
    pixDestroy(&ocr_image);
    return 0;

}

int main(int argc , char** argv){
    
    CLI::App app{"Email Extractor X29 by Palash Bauri"};
    string pdf_file = "";
    string image_file = "";
    string output_file = "";
    app.add_option("-p,--pdf" , pdf_file , "PDF File to Extract Emails from");
    app.add_option("-i,--image" , image_file , "Image File to Extract Emails from");
    app.add_option("-o,--out" , output_file , "Output File to Save Emails");
    CLI11_PARSE(app, argc, argv);
    if (output_file.length() <= 0){ 
        if (pdf_file.length() >= 0) {
            output_file = pdf_file + ".txt";
        }else if (image_file.length() >= 0) {
            output_file = image_file + ".txt";
        }

    }
    if (pdf_file.length() > 0 || image_file.length() > 0){
        convert(argc , argv  , pdf_file , image_file , output_file);
    }else{
        cout << "Error : No Input File" << endl;
    }

    return 0;

}
