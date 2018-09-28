#include <fstream>
enum flag{C,Z,I,D,B,V=6,S=7};/*
    C-carry
    Z-Zero
    I-Interrupt disable
    D-Decimal mode
    B-Break
    V-Overflow
    S-Negative flag
*/
#include <fstream>

class cpu_util{
    public:
    unsigned char A,X,Y;
    unsigned char flag;
    unsigned char SP;
    unsigned short PC;
    cpu_util();
    unsigned char *memory;
    int read();
};
cpu_util::cpu_util(){
    A=X=Y=0;
    SP=0xff;
    PC=0x0600;
    memory=new unsigned char[4096];
}
int cpu_util::read(){
    std::ifstream file;
    unsigned char *mem=&memory[PC];
    file.open("1.bin",std::ios::binary|std::ios::ate);
    file.seekg(0,file.end);
    int len=file.tellg();
    file.seekg(0,file.beg);
    char *ch=new char[4096];
    file.read(ch,len);
    for(int i=0;i<len;i++){
        mem[i]=(unsigned char)ch[i];
    }
    return len;
}
