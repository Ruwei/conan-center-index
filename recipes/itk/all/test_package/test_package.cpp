#include "itkLightObject.h"

#include <iostream>
#include <vector>
#include <string>


#include <itkImageSource.h>
#include <itkImageIOFactory.h>
#include <itkImageSeriesReader.h>
#include <itkMetaImageIOFactory.h>

class Test : public itk::LightObject {
public:
    typedef itk::SmartPointer<Test> Pointer;
    static Pointer New() { return new Test(); }
    const char *GetNameOfClass() { return "Test"; }
};

using ReaderType = itk::ImageSeriesReader<itk::Image<float,3>>;

int main(int, char **)
{
   // itk::MetaImageIOFactory::RegisterOneFactory();
    Test::Pointer test = Test::New();
    std::cout << test->GetNameOfClass() << std::endl;
    auto reader=ReaderType::New();
    std::vector<std::string> filenames={"test.mha"};
    reader->SetFileNames(filenames);
    try
    {
        reader->Update();
        std::cout << "success.\n" << std::endl;
    }
    catch (const std::exception &)
    {
        std::cout << "fail.\n" << std::endl;
    }
    return 0;
}
