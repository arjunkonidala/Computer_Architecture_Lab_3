#include <iostream>
#include <fstream>
using namespace std;

string d2b(int num,int nob)
          {
            if(num<0)
              {
                 int m=1;

                 for(int i=0;i<nob;i++)
                    {
                       m*=2;
                    }
                 num+=m;
              }
            
            string bin(nob,'0');
            
            for(int i=0;i<nob;i++)
               {
                  bin[nob-1-i]=num&1;
                  num=num>>1;
               }
             
            return bin;

          }

char bx(char *a)
    {
        int x = 1;
        int sum = 0;

        for (int i = 0; i < 4; i++)
            {
                sum += (x * a[3 - i]);
                x *= 2;
            }

        int y = '0';

        if (sum / 10)
           {
                y = 'a';
           }

        y += (sum % 10);    

        return y;

    }

struct s3  // For R and I formats
    {
        s3(string a, int b, int c)
          {
            inst = a;
            f3 = b;
            f7 = c;
          }
          
        s3()
         {
            inst = "0";
            f3 = 0;
            f7 = 0;
         };

        string inst;
        int f3;
        int f7;

    };

struct s2
     {
        string a;
        int b;
     };

s2 aliastable[65] = { 
                          {"x0", 0}, {"x1", 1}, {"x2", 2}, {"x3", 3}, {"x4", 4}, {"x5", 5}, {"x6", 6}, {"x7", 7}, {"x8", 8}, {"x9", 9}, {"x10", 10}, {"x11", 11}, {"x12", 12}, {"x13", 13}, {"x14", 14}, {"x15", 15}, {"x16", 16}, {"x17", 17}, {"x18", 18}, {"x19", 19}, {"x20", 20}, {"x21", 21}, {"x22", 22}, {"x23", 23}, {"x24", 24}, {"x25", 25}, {"x26", 26}, {"x27", 27}, {"x28", 28}, {"x29", 29}, {"x30", 30}, {"x31", 31}, {"zero", 0}, {"ra", 1}, {"sp", 2}, {"gp", 3}, {"tp", 4}, {"t0", 5}, {"t1", 6}, {"t2", 7}, {"s0", 8},{"fp",8}, {"s1", 9}, {"a0", 10}, {"a1", 11}, {"a2", 12}, {"a3", 13}, {"a4", 14}, {"a5", 15}, {"a6", 16}, {"a7", 17}, {"t3", 28}, {"t4", 29}, {"t5", 30}, {"t6", 31}, {"s2", 18}, {"s3", 19}, {"s4", 20}, {"s5", 21}, {"s6", 22}, {"s7", 23}, {"s8", 24}, {"s9", 25}, {"s10", 26}, {"s11", 27}
                    };


s3 rftable[8];

s3 iftable[9];

s3 ilftable[7];

s3 ijftable[1];

s3 sftable[4];

s3 bftable[6];

s3 uftable[1];

s3 ujftable[1];


int ifrf(string s)
        {
            if (s == "add")
            {
                return 1;
            }
             
            else if (s == "sub")
            {
                return 1;
            }

            else if (s == "and")
            {
                return 1;
            }

            else if (s == "or")
            {
                return 1;
            }
            
            else if (s == "xor")
            {
                return 1;
            }
            
            else if (s == "sll")
            {
                return 1;
            }
            
            else if (s == "srl")
            {
                return 1;
            }
            
            else if (s == "sra")
            {
                return 1;
            }
            
            
            return 0;
        
        }


int ifif(string s)
        {
            if (s == "addi")
            {
                return 1;
            }
            
            else if (s == "andi")
            {
                return 1;
            }

            else if (s == "ori")
            {
                return 1;
            } 

            else if (s == "xori")
            {
                return 1;
            }

            else if (s == "slli")
            {
                return 1;
            }

            else if (s == "srli")
            {
                return 1;
            }

            else if (s == "srai")
            {
                return 1;
            }


            return 0;
        }


int ifilf(string s)
         {
            if (s == "lb")
            {
                return 1;
            }

            else if (s == "lh")
            {
              return  1;
            }

            else if (s == "lw")
            {
                return 1;
            }

            else if (s == "ld")
            {
                return 1;
            }

            else if (s == "lbu")
            {
                return 1;
            }

            else if (s == "lhu")
            {
                return 1;
            }

            else if (s == "lwu")
            {
                return 1;
            }
            return 0;
         }


int ifijf(string s)
         {
            if (s == "jalr")
            {
                return 1;
            }return 0;
         }



int ifsf(string s)
        {
            if (s == "sb")
            {
                return 1;
            }
            
            else if (s == "sh")
            {
                return 1;
            }

            else if (s == "sw")
            {
                return 1;
            } 

            else if (s == "sd")
            {
                return 1;
            }

            return 0;
        }


int ifbf(string s)
        {
            if (s == "beq")
            {
                return 1;
            }
            
            else if (s == "bne")
            {
                return 1;
            }

            else if (s == "blt")
            {
                return 1;
            } 

            else if (s == "bge")
            {
                return 1;
            }

            else if (s == "bltu")
            {
                return 1;
            }

            else if (s == "bgeu")
            {
                return 1;
            }

            return 0;
        }

int ifuf(string s)
        {
            if (s == "lui")
            {
                return 1;
            }

            return 0;
        }
string checker(string a){
                for(int i=0;i<a.size();i++){
                    a[i]+='0';
                }return a;
              }
int ifujf(string s)
        {
            if (s == "jal")
            {
                return 1;
            }
            
            return 0;
        }



string rformat(s3 s, int a, int b, int c)
            {
                string f3(3, '0');
                int f = s.f3;

                for (int i = 0; i < 3; i++)
                    {
                        f3[2 - i] = f & 1;
                        f = f >> 1;
                    }
                
                f = s.f7;
                string f7(7, '0');

                for (int i = 0; i < 7; i++)
                    {
                        f7[6 - i] = (f & 1);
                        f = f >> 1;
                    }

                string rd(5, '0');
                string rs1(5, '0');
                string rs2(5, '0');
                f = a;

                for (int i = 0; i < 5; i++)
                    {
                        rd[4 - i] = (f & 1);
                        f = f >> 1;
                    }

                f = b;

                for (int i = 0; i < 5; i++)
                    {
                        rs1[4 - i] = f & 1;
                        f = f >> 1;
                    }

                f = c;

                for (int i = 0; i < 5; i++)
                    {
                        rs2[4 - i] = f & 1 ;
                        f = f >> 1;
                    }

                string opcode = "0110011";

                for (int i = 0; i < 7; i++)
                    {
                        opcode[i] -= '0';
                    }

                string bi = f7 + rs2 + rs1 + f3 + rd + opcode;

                string h(8, '0');

                for (int i = 0; i < 8; i++)
                    {
                        h[i] = bx(&(bi[0]) + 4 * i);
                    }
                return h;
            }


string iformat(s3 s,int a,int b,int c)
              {
                    int f = s.f3;                
                    string f3(3,'0');

                    for (int i = 0; i < 3; i++)
                        {
                           f3[2 - i] = f & 1;
                           f = f >> 1;
                        }

                    f = a;
                    string rd(5,'0');
                     
                    for (int i = 0; i < 5; i++)
                        {
                          rd[4 - i] = (f & 1);
                          f = f >> 1;
                        }

                    f = b;
                    string rs1(5,'0');

                    for (int i = 0; i < 5; i++)
                        {
                            rs1[4 - i] = f & 1;
                            f = f >> 1;
                        }

                    string opcode = "0010011";

                    for (int i = 0; i < 7; i++)
                        {
                            opcode[i] -= '0';
                        }

                    f=s.f7;
                    string dummy="000000";

                    for(int i=0;i<6;i++)
                       {
                          dummy[i]-='0';
                       }

                    string imm(12,'0');

                    if(f==0)
                      {
                         imm = d2b(c,12);
                      }  

                    else if(f==1)
                           {
                              string dummy="000000";
                            
                              for(int i=0;i<6;i++)
                                 {
                                   dummy[i]-='0';
                                 }
                              
                              imm=dummy+d2b(c,6);
                            }

                    string bin=imm+rs1+f3+rd+opcode;

                    if(s.inst=="srai")
                      {
                        bin[1]=1;
                      }
                       
                    string h(8, '0');
                    
                    for(int i = 0; i < 8; i++)
                        {
                           h[i] = bx(&(bin[0]) + 4 * i);
                        }
                
                     return h;
              }


string ilformat(s3 s,int a,int b,int c)
              {
                    int f = s.f3;                
                    string f3(3,'0');

                    for (int i = 0; i < 3; i++)
                        {
                           f3[2 - i] = f & 1;
                           f = f >> 1;
                        }

                    f = a;
                    string rd(5,'0');
                     
                    for (int i = 0; i < 5; i++)
                        {
                          rd[4 - i] = (f & 1);
                          f = f >> 1;
                        }

                    f = b;
                    string rs1(5,'0');

                    for (int i = 0; i < 5; i++)
                        {
                            rs1[4 - i] = f & 1;
                            f = f >> 1;
                        }

                    string opcode = "0000011";

                    for (int i = 0; i < 7; i++)
                        {
                            opcode[i] -= '0';
                        }

                    f=s.f7;
                    

                    string imm(12,'0');

                    
                         imm = d2b(c,12);
                      

                    string bin=imm+rs1+f3+rd+opcode;

                   
                       
                    string h(8, '0');
                    
                    for(int i = 0; i < 8; i++)
                        {
                           h[i] = bx(&(bin[0]) + 4 * i);
                        }
                
                     return h;
              }


string ijformat(s3 s,int a,int b,int c)
                {
                    int f = s.f3;                
                    string f3(3,'0');

                    for (int i = 0; i < 3; i++)
                        {
                           f3[2 - i] = f & 1;
                           f = f >> 1;
                        }

                    f = a;
                    string rd(5,'0');
                     
                    for (int i = 0; i < 5; i++)
                        {
                          rd[4 - i] = (f & 1);
                          f = f >> 1;
                        }

                    f = b;
                    string rs1(5,'0');

                    for (int i = 0; i < 5; i++)
                        {
                            rs1[4 - i] = f & 1;
                            f = f >> 1;
                        }

                    string opcode = "1100111";

                    for (int i = 0; i < 7; i++)
                        {
                            opcode[i] -= '0';
                        }

                    f=s.f7;
                    

                    string imm(12,'0');

                    
                         imm = d2b(c,12);
                      

                    string bin=imm+rs1+f3+rd+opcode;

                   
                       
                    string h(8, '0');
                    
                    for(int i = 0; i < 8; i++)
                        {
                           h[i] = bx(&(bin[0]) + 4 * i);
                        }
                
                     return h;
                }



string sformat(s3 s, int a, int b, int c)
              { 
                string f3(3, '0');
                int f = s.f3;

                for (int i = 0; i < 3; i++)
                    {
                        f3[2 - i] = f & 1;
                        f = f >> 1;
                    }

                string rs1(5, '0');
                string rs2(5, '0');

                f = a;

                for (int i = 0; i < 5; i++)
                    {
                        rs1[4 - i] = (f & 1);
                        f = f >> 1;
                    }
                
                f = b;

                for (int i = 0; i < 5; i++)
                    {
                        rs2[4 - i] = f & 1;
                        f = f >> 1;
                    }
                
                string opcode = "0100011";

                for (int i = 0; i < 7; i++)
                    {
                        opcode[i] -= '0';
                    }
                
                string imm = d2b(c,12);
                string imm1(7,'0'),imm2(5,'0');

                for(int i=0;i<7;i++){
                    imm1[i]=imm[i];
                }
                for(int i=0;i<5;i++){
                    imm2[i]=imm[7+i];
                }
                
                string bin = imm1+ rs1 + rs2 +f3+ imm2 + opcode;
                   
                string h(8, '0');
                
                    
                    for(int i = 0; i < 8; i++)
                        {
                           h[i] = bx(&(bin[0]) + 4 * i);
                        }
                
                     return h;
                                      
              } 
              



string bformat()
              {
                 
              }



string ujformat()
               {

               }




int main()
    {
        ifstream file1("input.s");
        ofstream file2("output.hex");
        string ins;
        int line = 1;

        while(getline(file1,ins))
             {
        
                 string m;
                 for (int i = 0; i < ins.size(); i++)
                     {
                       if (ins[i] == ' ')
                          {
                              break;
                          }
                     
                       m.push_back(ins[i]);
                     }

                 if (ifrf(m))
                    {
                        rftable[0] = s3("add", 0, 0);
                        rftable[1] = s3("sub", 0x0, 0x20);
                        rftable[2] = s3("xor", 0x4, 0x00);
                        rftable[3] = s3("or", 0x6, 0x00);
                        rftable[4] = s3("and", 0x7, 0x00);
                        rftable[5] = s3("sll", 0x1, 0x00);
                        rftable[6] = s3("srl", 0x5, 0x00);
                        rftable[7] = s3("sra", 0x5, 0x20);

                        s3 data("0", 0, 0);

                        int k = 0;
                        string rd, rs1, rs2;
                        int rdi = -1, rs1i = -1, rs2i = -1;

                        for (; k < ins.size(); k++)
                            {
                                if (ins[k] == ' ')
                                   {
                                        k++;
                                        break;
                                   }
                            }

                        for (; k < ins.size(); k++)
                            {
                                if (ins[k] == ',')
                                    {
                                        k+=2;
                                        break;
                                    }
                                rd.push_back(ins[k]);
                            }

                        for (; k < ins.size(); k++)
                            {
                                if (ins[k] == ',')
                                    {
                                        k+=2;
                                        break;
                                    }

                                rs1.push_back(ins[k]);
                            }

                        for (; k < ins.size(); k++)
                            {
                                if (ins[k] == ',')
                                {
                                    k+=2;
                                    break;
                                }

                                rs2.push_back(ins[k]);
                            }
                            int e=0;

                        for (int i = 0; i < 65; i++)
                            {
                                if (rs1 == aliastable[i].a)
                                {
                                    rs1i = aliastable[i].b;e+=1;
                                }

                                if (rs2 == aliastable[i].a)
                                {
                                    rs2i = aliastable[i].b;e+=1;
                                }

                                if (rd == aliastable[i].a)
                                {
                                    rdi = aliastable[i].b;e+=1;
                                }

                            }

                        if(e!=3)
                        {
                            file2<<"error in line "<<line<<"\n";
                            return 0;
                        }

                        for (int i = 0; i < 10; i++)
                            {
                                if (rftable[i].inst == m)
                                    {
                                        data = rftable[i];
                                        break;
                                    }
                            }

                        file2 << rformat(data, rdi, rs1i, rs2i)<<endl;
                        line++;
                    }

                else if(ifif(m))
                    {
                            iftable[0] = s3("addi", 0, 0);
                            iftable[1] = s3("srai", 0x5,1);
                            iftable[2] = s3("xori", 0x4, 0x00);
                            iftable[3] = s3("ori", 0x6, 0x00);
                            iftable[4] = s3("andi", 0x7, 0x00);
                            iftable[5] = s3("slli", 0x1, 0x1);
                            iftable[6] = s3("srli", 0x5, 0x1);


                            s3 data("0", 0, 0);

                            int k = 0;
                            string rd, rs1, imm;
                            int rdi = -1, rs1i = -1;

                            for (  ; k < ins.size(); k++)
                                {
                                    if (ins[k] == ' ')
                                        {
                                            k++;
                                            break;
                                        }
                                }

                            for (  ; k < ins.size(); k++)
                                {
                                    if (ins[k] == ',')
                                        {
                                            k+=2;
                                            break;
                                        }

                                    rd.push_back(ins[k]);
                                }

                            for (  ; k < ins.size(); k++)
                                {
                                    if (ins[k] == ',')
                                        {
                                            k+=2;
                                            break;
                                        }

                                    rs1.push_back(ins[k]);
                                }

                            for (  ; k < ins.size(); k++)
                                {
                                    if (ins[k] == ',')
                                        {
                                            k+=2;
                                            break;
                                        }

                                    imm.push_back(ins[k]);
                                }
                                
                                int e=0;

                            for (int i = 0; i < 65; i++)
                                {
                                    if (rs1 == aliastable[i].a)
                                        {
                                            rs1i = aliastable[i].b;e+=7;
                                        }
                                    
                                    if (rd == aliastable[i].a)
                                        {
                                            rdi = aliastable[i].b;e+=55;
                                        }

                                }
                                
                                if(e!=62)
                                {
                                    file2<<"error in line "<<line<<"\n";

                                    return 0;
                                }

                            for (int i = 0; i < 7; i++)
                                {
                                    if (iftable[i].inst == m)
                                        {
                                            data = iftable[i];
                                            break;
                                        }
                                }

                            int sign=0;

                            if(imm[0]=='-')
                              {
                                sign=1;
                              }
                            
                            int immv =0;
                            int power=1;
                            for(int i=imm.size()-1;i>=sign;i--)
                               {
                                  immv+=(imm[i]-'0')*power;
                                  power=power*10;
                                
                                  
                               }
                            if(sign)immv=-immv;
                            
                            for(int i=0;i<7;i++){
                                if(iftable[i].inst==m){
                                    
                                    if(iftable[i].f7==1){
                                        if(immv>=0&&immv<64){

                                        }
                                        else{
                                            cout<<"immediate value out of bound in line "<<line<<endl;return 0;
                                        }
                                    }
                                    else{
                                        if(immv>=-2048&&immv<=2047){

                                        }
                                        else{
                                             cout<<"immediate value out of bound in line "<<line<<endl;return 0;
                                        }
                                    }
                                }
                            }
                            
                            file2<<iformat(data,rdi,rs1i,immv)<<endl;
                            line++;
                    }
                    

                 else if(ifilf(m))
                        {                             
                                ilftable[0] = s3("lb", 0,0 );
                                ilftable[1] = s3("lh", 0x1,0);
                                ilftable[2] = s3("lw", 0x2,0 );
                                ilftable[3] = s3("ld", 0x3,0 );
                                ilftable[4] = s3("lbu", 0x4,1);
                                ilftable[5] = s3("lhu", 0x5,1 );
                                ilftable[6] = s3("lwu", 0x6,1 );
                                s3 data("0", 0, 0);
                                int k=0;
                                string rd,rs1,imm;
                                int rdi,rs1i;
                                for (  ; k < ins.size(); k++)
                                {
                                    if (ins[k] == ' ')
                                        {
                                            k++;
                                            break;
                                        }
                                }

                            for (  ; k < ins.size(); k++)
                                {
                                    if (ins[k] == ',')
                                        {
                                            k+=2;
                                            break;
                                        }

                                    rd.push_back(ins[k]);
                                }
                            for (  ; k < ins.size(); k++)
                                {
                                    if (ins[k] == '(')
                                        {
                                            k++;
                                            break;
                                        }

                                    imm.push_back(ins[k]);
                                }
                            for (  ; k < ins.size(); k++)
                                {
                                    if (ins[k] == ')')
                                        {
                                            k++;
                                            break;
                                        }

                                rs1.push_back(ins[k]);
                                }
                                int e=0;
                                for (int i = 0; i < 65; i++)
                                {
                                    if (rs1 == aliastable[i].a)
                                        {
                                            rs1i = aliastable[i].b;e+=7;
                                        }
                                    
                                    if (rd == aliastable[i].a)
                                        {
                                            rdi = aliastable[i].b;e+=55;
                                        }

                                }
                                
                                if(e!=62)
                                {
                                    file2<<"error in line "<<line<<"\n";

                                    return 0;
                                }

                            for (int i = 0; i < 7; i++)
                                {
                                    if (ilftable[i].inst == m)
                                        {
                                            data = ilftable[i];
                                            break;
                                        }
                                }
                                

                            int sign=0;

                            if(imm[0]=='-')
                              {
                                sign=1;
                              }
                            
                            int immv =0;
                            int power=1;
                            for(int i=imm.size()-1;i>=sign;i--)
                               {
                                  immv+=(imm[i]-'0')*power;
                                  power=power*10;
                                
                                  
                               }
                            if(sign)immv=-immv;
                            if(!(immv>=-2048&&immv<=2047)){
                                file2<<"immediate value out of bound line "<<line<<endl;
                            }
                        file2<<ilformat(data,rdi,rs1i,immv)<<endl;
                            line++;

                        } 


                 else if(ifijf(m))
                        {
                                 ijftable[0] = s3("jalr", 0x0, 0);
                                 s3 data("0", 0, 0);
                                 
                                 data=ijftable[0];
                                int k=0;
                                string rd,rs1,imm;
                                int rdi,rs1i;
                                for (  ; k < ins.size(); k++)
                                {
                                    if (ins[k] == ' ')
                                        {
                                            k++;
                                            break;
                                        }
                                }

                            for (  ; k < ins.size(); k++)
                                {
                                    if (ins[k] == ',')
                                        {
                                            k+=2;
                                            break;
                                        }

                                    rd.push_back(ins[k]);
                                }
                            for (  ; k < ins.size(); k++)
                                {
                                    if (ins[k] == ',')
                                        {
                                            k+=2;
                                            break;
                                        }

                                    rs1.push_back(ins[k]);
                                }
                            for (  ; k < ins.size(); k++)
                                {
                                    if (ins[k] == ',')
                                        {
                                            k++;
                                            break;
                                        }

                                    imm.push_back(ins[k]);
                                }
                                int e=0;
                                for (int i = 0; i < 65; i++)
                                {
                                    if (rs1 == aliastable[i].a)
                                        {
                                            rs1i = aliastable[i].b;e+=7;
                                        }
                                    
                                    if (rd == aliastable[i].a)
                                        {
                                            rdi = aliastable[i].b;e+=55;
                                        }

                                }
                                cout<<e;
                                if(e!=62)
                                {
                                    file2<<"error in line "<<line<<"\n";

                                    return 0;
                                }

                            
                                

                            int sign=0;

                            if(imm[0]=='-')
                              {
                                sign=1;
                              }
                            
                            int immv =0;
                            int power=1;
                            for(int i=imm.size()-1;i>=sign;i--)
                               {
                                  immv+=(imm[i]-'0')*power;
                                  power=power*10;
                                
                                  
                               }
                            if(sign)immv=-immv;cout<<immv;
                            if(!(immv>=-2048&&immv<=2047))
                            {
                                file2<<"immediate value out of bound in line "<<line<<endl;
                            }
                            file2<<ijformat(data,rdi,rs1i,immv)<<endl;
                            line++;


                        } 
                        else if(ifbf(m))
                        {
                                 bftable[0] = s3("beq", 0x0,0 );
                                 bftable[1] = s3("bne", 0x1, 0);
                                 bftable[2] = s3("blt", 0x4,0 );
                                 bftable[3] = s3("bge", 0x5, 0);
                                 bftable[4] = s3("bltu", 0x6,0 );
                                 bftable[5] = s3("bgeu", 0x7, 0);
                                 s3 data("0", 0, 0);
                                 

                            
                        }
                 
                 else if(ifsf(m))
                        {
                                 sftable[0] = s3("sb", 0x0,0 );
                                 sftable[1] = s3("sh", 0x1, 0);
                                 sftable[2] = s3("sw", 0x2, 0);
                                 sftable[3] = s3("sd", 0x3, 0);
                                 s3 data("0", 0, 0);
                                
                                int k=0;
                                string rd,rs1,imm;
                                int rdi,rs1i;
                                for (  ; k < ins.size(); k++)
                                {
                                    if (ins[k] == ' ')
                                        {
                                            k++;
                                            break;
                                        }
                                }

                            for (  ; k < ins.size(); k++)
                                {
                                    if (ins[k] == ',')
                                        {
                                            k+=2;
                                            break;
                                        }

                                    rd.push_back(ins[k]);
                                }
                            for (  ; k < ins.size(); k++)
                                {
                                    if (ins[k] == '(')
                                        {
                                            k++;
                                            break;
                                        }

                                    imm.push_back(ins[k]);
                                }
                            for (  ; k < ins.size(); k++)
                                {
                                    if (ins[k] == ')')
                                        {
                                            k++;
                                            break;
                                        }

                                rs1.push_back(ins[k]);
                                }
                                int e=0;
                                for (int i = 0; i < 65; i++)
                                {
                                    if (rs1 == aliastable[i].a)
                                        {
                                            rs1i = aliastable[i].b;e+=7;
                                        }
                                    
                                    if (rd == aliastable[i].a)
                                        {
                                            rdi = aliastable[i].b;e+=55;
                                        }

                                }
                                
                                if(e!=62)
                                {
                                    file2<<"error in line "<<line<<"\n";

                                    return 0;
                                }

                            for (int i = 0; i < 4; i++)
                                {
                                    if (sftable[i].inst == m)
                                        {
                                            data = sftable[i];
                                            break;
                                        }
                                }
                                

                            int sign=0;

                            if(imm[0]=='-')
                              {
                                sign=1;
                              }
                            
                            int immv =0;
                            int power=1;
                            for(int i=imm.size()-1;i>=sign;i--)
                               {
                                  immv+=(imm[i]-'0')*power;
                                  power=power*10;
                                
                                  
                               }
                               
                            if(sign)immv=-immv;
                            if(!(immv>=-2048&&immv<=2047)){
                                file2<<"immediate value out of bound line "<<line<<endl;
                            }
                        file2<<sformat(data,rdi,rs1i,immv)<<endl;
                            line++;
                        }

                 

                 else if(ifuf(m))
                        {string opcode="0110111";
                        for(int i=0;i<7;i++){
                            opcode[i]-='0';
                        }string imm;
                            int k=0;int co=0;
                            for(;k<ins.size();k++){
                                 if (ins[k] == ' ')
                                    {

                                        k++;break;
                                    }
                            }
                            string r;
                            for(;k<ins.size();k++){
                                if(ins[k]==','){
                                    k+=2;break;
                                }
                                r.push_back(ins[k]);
                                
                            }int r1=0;cout<<r;
                            for(int i=0;i<65;i++){
                                if(aliastable[i].a==r){
                                    r1=aliastable[i].b;
                                }
                            }cout<<r1;
                            for(;k<ins.size();k++){
                                imm.push_back(ins[k]);
                            }if(imm[0]=='-'){
                                file2<<"immeddiate out of bound in line "<<line<<endl;
                            }
                            int immv =0;
                            int power=1;
                            string r2(5,'0');
                             for (int i = 0; i < 5; i++)
                            {
                            r2[4 - i] = r1 & 1;
                            r1= r1>> 1;
                            }
                    
                            for(int i=imm.size()-1;i>=0;i--)
                               {
                                  immv+=(imm[i]-'0')*power;
                                  power=power*10;
                                
                                  
                               }
                            cout<<immv;
                            if(immv>=(1<<20)){
                                file2<<"immediate value out of bound in line "<<line<<endl;
                            }
                            string x=d2b(immv,20);
                            string a=x+r2+opcode;
                             string h(8, '0');
                
                    
                        for(int i = 0; i < 8; i++)
                        {
                           h[i] = bx(&(a[0]) + 4 * i);
                        }
                        file2<<h<<endl;
                        }
                /*      
                 else if(ifujf(m))
                        {
                                  ujftable[0] = s3("jal", 0x0, );
                                  s3 data("0", 0, 0);
                        }     




        return 0;*/

    }
}