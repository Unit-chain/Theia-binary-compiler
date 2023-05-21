////
//// Created by Kirill Zhukov on 21.05.2023.
////
//#include "BinaryWriter.h"
//
//#include <utility>
//
//BinaryWriter::BinaryWriter(char* path) {
//    this->path = std::shared_ptr<char>(path);
//    FILE *f = fopen(this->path.get(), "wb");
//    this->fp = std::unique_ptr<FILE>(f);
//}
//
//void BinaryWriter::setBs(BytecodeStream &bs) {
//    BinaryWriter::bs = bs;
//}
//
//ARM64BinaryWriter::ARM64BinaryWriter(char *path) : BinaryWriter(path) {}
//
//void ARM64BinaryWriter::write() {
//    void *dtt[] = {
//            &&stop,
//            &&go_to,
//            &&swap,
//            &&iadd,
//            &&astorea
//            /// continue
//    };
//    while (this->bs.hasMoreBytes()) {
//       uint8_t instruction = bs.readByte();
//       goto *dtt[instruction];
//
//       stop: {
//           return;
//       };
//       go_to: {
//           instruction = bs.readByte();
//           goto *dtt[instruction];
//       };
//       swap: {
//            // swap two references
//           instruction = bs.readByte();
//           goto *dtt[instruction];
//       };
//       iadd: {
//           // sum two numbers
//           instruction = bs.readByte();
//           goto *dtt[instruction];
//       };
//       astorea: {
//           // store reference into array
//           instruction = bs.readByte();
//           goto *dtt[instruction];
//       };
//    }
//}
//
//std::shared_ptr<char> ARM64BinaryWriter::iadd() {
//    char *iadd = (char*) std::malloc(8);
//    iadd = (char*) "add x0, x1, x1\n";
//    return std::shared_ptr<char>(iadd);
//}
//
//X86BinaryWriter::X86BinaryWriter(char *path) : BinaryWriter(path) {}
//
//void X86BinaryWriter::write() {
//    void *dtt[] = {
//            &&stop,
//            &&go_to,
//            &&swap,
//            &&iadd,
//            &&astorea
//            /// continue
//    };
//    while (this->bs.hasMoreBytes()) {
//        uint8_t instruction = bs.readByte();
//        goto *dtt[instruction];
//
//        stop: {
//        return;
//    };
//        go_to: {
//        instruction = bs.readByte();
//        goto *dtt[instruction];
//    };
//        swap: {
//        // swap two references
//        instruction = bs.readByte();
//        goto *dtt[instruction];
//    };
//        iadd: {
//        // sum two numbers
//        instruction = bs.readByte();
//        goto *dtt[instruction];
//    };
//        astorea: {
//        // store reference into array
//        instruction = bs.readByte();
//        goto *dtt[instruction];
//    };
//    }
//}