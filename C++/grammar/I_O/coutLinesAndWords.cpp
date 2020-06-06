#include <iostream>
#include <fstream>

using std::ios;

bool isAlpha(const char c)
{
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
        return true;
    return false;
}

void getLinesAndWords(const char* path, int &lines, int &words)
{
    std::ifstream reader(path);
    lines = 0;
    words = 0;
    bool isInword = false;
    char buffer[1024 * 4];

    while(!reader.eof())
    {
        reader.getline(buffer, 1024 * 2);
        int i = 0;
        ++lines;
        while(buffer[i++] != 0)
        {
            if(!isAlpha(buffer[i]))
            {
                isInword = false; 
            }
            else if (!isInword && isAlpha(buffer[i]))
            {
                ++words;
                isInword = true;
            }
        }
    }
}

int main()
{
    const char * path = "./demo2.cpp";
    int lines = 0;
    int words = 0;
    getLinesAndWords(path, lines, words);
    std::cout << path << " has " << lines << " lines , has " << words << " words" << std::endl;
}