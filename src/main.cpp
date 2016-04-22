#include <iostream>
#include <fstream>

// Project Specific
#include "compactPointer.h"
#include "trie.h"
#include

struct record{
    string header;
    string sequence;
};


record get_record(ifstream& ifs){
    string this_header;
    string this_seq;
    getline(ifs, this_header);
    getline(ifs, this_seq);

    record new_record = {this_header, this_seq};

    return new_record;
}


int main(int argc, char **argv) {
    std::cout << "Test Smart gitPointer to Trie" << "\n";

    CompactPointer<Trie> prefix = new Trie();
    std::cout << "Pointer size: " << sizeof(&prefix) << "\n";;

    ifstream ifs;
    ifs.open ("test_in.fasta", ifstream::in);

    record this_record;
    char x;
    while( ifs.get(x)) {
        this_record = get_record(ifs);
        prefix->add(this_record.sequence);
        std::cout << "Prefix Length: " << prefix->get_size() << "\n";
    }

    ifs.close();

    return 0;
}
