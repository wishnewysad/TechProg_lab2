#include "file_utils.h"

#include <iostream>
#include <fstream>

#define COUNT_OF_SENTENCES 3
#define MAX_BUFF_SIZE 1024

bool is_end_point(unsigned char ch)
{
    unsigned char end_point[] = {'.', '!', '?'};
    bool isEnd = false;

    for (unsigned char& i : end_point) {
        if(i == ch)
            isEnd = true;
    }

    return isEnd;
}

void read_from_file(const char* file_name)
{
    std::ifstream in;
    in.open(file_name);

    if (!in.is_open())
        throw "File doesn't exist";

    unsigned char_count     = 0;
    unsigned sentence_count = 0;

    auto** sentences = new char* [COUNT_OF_SENTENCES];
    char* sentence = nullptr;

    char buffer[MAX_BUFF_SIZE] = {0};

    do {
	buffer[char_count++] = in.get();

        if(is_end_point(buffer[char_count - 1])) {
	        sentence_count++;
	        buffer[char_count++] = '\0';

			sentence = new char[char_count];

            for (int i = 0; i < char_count; ++i)
                sentence[i] = buffer[i];

            sentences[sentence_count - 1] = sentence;

            sentence = nullptr;
            char_count = 0;
        }

        if(sentence_count == COUNT_OF_SENTENCES)
            break;

    } while (!in.eof());

    for (int i = COUNT_OF_SENTENCES - 1, j = 0; i >= 0; --i)
        std::cout << j++ + 1 << ". " << sentences[i] << std::endl;

    for (int i = 0; i < COUNT_OF_SENTENCES; ++i) {
        delete[] sentences[i];
    }
    delete[] sentences;

    std::cout << "\n";
}