#include <iostream>
#include <array>

using namespace std;

bool* padding(bool *msg, int l);
array<bool, 4> convert_hexa_digit__2_bool(char);
bool* convert_hexa_2_bool(string);
void innerCompression(bool* a, bool* b, bool* c, bool* d, bool* e, bool* f, bool* g, bool* h, const bool* kt, const bool* wt, const int size);

const int SIZE_OF_BLOCK = 2;
const int SIZE_OF_ADDRESS = 1;
bool** parsing(bool*,int);
bool** parsing_w(bool*,int);
void printSth(bool**);

bool* rot(bool*,int);
bool* shf(bool*,int);
bool* rot_n(bool *, int, int);
bool* shf_n(bool *, int, int);
bool* xor_array(const bool*,const bool*,int);
bool* and_array(const bool*,const bool*, int);
bool* add_array(const bool*,const bool*, int);
bool* twos_comp_array(const bool*,int);
bool* not_array(const bool*,int);
bool* assign_array(bool* bool_array, const bool* assigner_array, int size, bool initial);
bool** initK();


int main() {
    bool msg[] = {1, 1, 0, 1};
    bool msg1[] = {0, 1, 1, 0};
    bool *f1 = rot(msg,4);
    for(int i=0; i<4 ;i++){
        cout << f1[i];
    }
    bool *f2 = shf(msg,4);
    for(int i=0; i<4 ;i++){
        cout << f2[i];
    }


    return 0;
}


bool* /*??*/ compression(bool*** w, int size){
    // w [block number] [index of w] [index of bit in w]
    bool* h0 = convert_hexa_2_bool("6a09e667");
    bool* h1 = convert_hexa_2_bool("bb67ae85");
    bool* h2 = convert_hexa_2_bool("3c6ef372");
    bool* h3 = convert_hexa_2_bool("a54ff53a");
    bool* h4 = convert_hexa_2_bool("510e527f");
    bool* h5 = convert_hexa_2_bool("9b05688c");
    bool* h6 = convert_hexa_2_bool("1f83d9ab");
    bool* h7 = convert_hexa_2_bool("5be0cd19");
    bool** k = initK();
    bool* a;
    bool* b;
    bool* c;
    bool* d;
    bool* e;
    bool* f;
    bool* g;
    bool* h;
    a = assign_array(a, h0, size, true);
    b = assign_array(b, h1, size, true);
    c = assign_array(c, h2, size, true);
    d = assign_array(d, h3, size, true);
    e = assign_array(e, h4, size, true);
    f = assign_array(f, h5, size, true);
    g = assign_array(g, h6, size, true);
    h = assign_array(h, h7, size, true);

    return 0;
}

void innerCompression(bool* a, bool* b, bool* c, bool* d, bool* e, bool* f, bool* g, bool* h, const bool* kt, const bool* wt, const int size){
    bool* sigma1E = xor_array(xor_array(rot_n(e, size, 6), rot_n(e, size, 11), size), rot_n(e, size, 25), size);
    bool* chEFG = xor_array(
                and_array(e, f, size),
                xor_array( and_array(not_array(f, size), g, size)
                         , and_array(not_array(e, size), g, size)
                         , size
                         )
                , size
    );
    bool* t2 = add_array(
            h,
            add_array(
                    sigma1E,
                    add_array(
                            chEFG,
                            add_array(kt,wt,size),
                            size
                    ),
                    size
            ),
            size
    );

    bool* sigma0A = xor_array(xor_array(xor_array(rot_n(a, size, 2), rot_n(a, size, 13), size), rot_n(a, size, 22), size),
                              shf_n(a, size, 7), size);
    bool* majABC = xor_array(
            and_array(a, c, size),
            xor_array( and_array(a, b, size)
                    , and_array(b, c, size)
                    , size
            )
            , size
    );
    bool* cPlusD = add_array(c, d, size);
    bool* sigma2CplusD = xor_array(xor_array(xor_array(rot_n(cPlusD, size, 2), rot_n(cPlusD, size, 3), size),
                                             rot_n(cPlusD, size, 15), size),
                                   shf_n(cPlusD, size, 5), size);
    bool* t1 = add_array(
            sigma0A,
            add_array(
                    majABC,
                    sigma2CplusD,
                    size
            ),
            size
    );
    assign_array(h, g, size, false);
    assign_array(f, e, size, false);
    assign_array(d, c, size, false);
    assign_array(b, a, size, false);
    assign_array(g, f, size, false);
    assign_array(e, add_array(d, t1, size), size, false);
    assign_array(c, b, size, false);
    assign_array(a, add_array(t1, add_array(t1, add_array(t1, twos_comp_array(t2, size), size), size), size), size, false);
}

bool** /*32*/ initK(){
    bool ** k = new bool* [64];
    k[0] = convert_hexa_2_bool("428a2f98");
    k[1] = convert_hexa_2_bool("71374491");
    k[2] = convert_hexa_2_bool("b5c0fbcf");
    k[3] = convert_hexa_2_bool("e9b5dba5");
    k[4] = convert_hexa_2_bool("3956c25b");
    k[5] = convert_hexa_2_bool("59f111f1");
    k[6] = convert_hexa_2_bool("923f82a4");
    k[7] = convert_hexa_2_bool("ab1c5ed5");
    k[8] = convert_hexa_2_bool("d807aa98");
    k[9] = convert_hexa_2_bool("12835b01");
    k[10] = convert_hexa_2_bool("243185be");
    k[11] = convert_hexa_2_bool("550c7dc3");
    k[12] = convert_hexa_2_bool("72be5d74");
    k[13] = convert_hexa_2_bool("80deb1fe");
    k[14] = convert_hexa_2_bool("9bdc06a7");
    k[15] = convert_hexa_2_bool("c19bf174");

    k[16] = convert_hexa_2_bool("e49b69c1");
    k[17] = convert_hexa_2_bool("efbe4786");
    k[18] = convert_hexa_2_bool("0fc19dc6");
    k[19] = convert_hexa_2_bool("240ca1cc");
    k[20] = convert_hexa_2_bool("2de92c6f");
    k[21] = convert_hexa_2_bool("4a7484aa");
    k[22] = convert_hexa_2_bool("5cb0a9dc");
    k[23] = convert_hexa_2_bool("76f988da");
    k[24] = convert_hexa_2_bool("983e5152");
    k[25] = convert_hexa_2_bool("a831c66d");
    k[26] = convert_hexa_2_bool("b00327c8");
    k[27] = convert_hexa_2_bool("bf597fc7");
    k[28] = convert_hexa_2_bool("c6e00bf3");
    k[29] = convert_hexa_2_bool("d5a79147");
    k[30] = convert_hexa_2_bool("06ca6351");
    k[31] = convert_hexa_2_bool("14292967");

    k[32] = convert_hexa_2_bool("27b70a85");
    k[33] = convert_hexa_2_bool("2e1b2138");
    k[34] = convert_hexa_2_bool("4d2c6dfc");
    k[35] = convert_hexa_2_bool("53380d13");
    k[36] = convert_hexa_2_bool("650a7354");
    k[37] = convert_hexa_2_bool("766a0abb");
    k[38] = convert_hexa_2_bool("81c2c92e");
    k[39] = convert_hexa_2_bool("92722c85");
    k[40] = convert_hexa_2_bool("a2bfe8a1");
    k[41] = convert_hexa_2_bool("a81a664b");
    k[42] = convert_hexa_2_bool("c24b8b70");
    k[43] = convert_hexa_2_bool("c76c51a3");
    k[44] = convert_hexa_2_bool("d192e819");
    k[45] = convert_hexa_2_bool("d6990624");
    k[46] = convert_hexa_2_bool("f40e3585");
    k[47] = convert_hexa_2_bool("106aa070");

    k[48] = convert_hexa_2_bool("19a4c116");
    k[49] = convert_hexa_2_bool("1e376c08");
    k[50] = convert_hexa_2_bool("2748774c");
    k[51] = convert_hexa_2_bool("34b0bcb5");
    k[52] = convert_hexa_2_bool("391c0cb3");
    k[53] = convert_hexa_2_bool("4ed8aa4a");
    k[54] = convert_hexa_2_bool("5b9cca4f");
    k[55] = convert_hexa_2_bool("682e6ff3");
    k[56] = convert_hexa_2_bool("748f82ee");
    k[57] = convert_hexa_2_bool("78a5636f");
    k[58] = convert_hexa_2_bool("84c87814");
    k[59] = convert_hexa_2_bool("8cc70208");
    k[60] = convert_hexa_2_bool("90befffa");
    k[61] = convert_hexa_2_bool("a4506ceb");
    k[62] = convert_hexa_2_bool("be49a3f7");
    k[63] = convert_hexa_2_bool("c67178f2");

    return k;

}

bool* padding(bool *msg, int l){
    // l + 1 + (0...0) = SIZE_OF_BLOCK*k + (SIZE_OF_BLOCK - SIZE_OF_ADDRESS)
    int num_of_zeros;
    int k;
    const int last_block_size = SIZE_OF_BLOCK - SIZE_OF_ADDRESS; //448
    if((l+1)%SIZE_OF_BLOCK <= last_block_size)
    {
        num_of_zeros = (l+1)%SIZE_OF_BLOCK - last_block_size;
        k = (l+1)/SIZE_OF_BLOCK;
    }
    else
    {
        num_of_zeros = (SIZE_OF_BLOCK-(l+1)%SIZE_OF_BLOCK) + last_block_size;
        k = (l+1)/SIZE_OF_BLOCK + 1;
    }
    bool* padded_msg = new bool [l + 1 + num_of_zeros];
    for(int i = 0; i < l; i ++) padded_msg[i] = msg[i];
    padded_msg[l] = 1;
    for(int i = 0; i < num_of_zeros; i++){
        padded_msg[l+1+i] = 0;
    }

    return padded_msg;
}

void printSth(bool** data,int n,int m){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout << data[i][j];
        }
        cout << endl;
    }
}

bool** parsing(bool* data,int data_size){
    int number_of_blocks = (int)(data_size/SIZE_OF_BLOCK);
    bool **blocks = new bool*[number_of_blocks];
    for(int i = 0; i < data_size ;i++){
        if(i % SIZE_OF_BLOCK == 0){
            blocks[(int)(i/SIZE_OF_BLOCK)] = new bool[SIZE_OF_BLOCK];
        }
        blocks[(int)(i/SIZE_OF_BLOCK)][i%SIZE_OF_BLOCK] = data[i];
    }
    printSth(blocks,2,2);
    return blocks;
}

bool* rot_n(bool *data, int size, int n){
    bool* rot_res=data;
    for(int i = 0;i < n; i++){
        rot_res = rot(rot_res,size);
    }
    return rot_res;
}

bool* shf_n(bool *data, int size, int n){
    bool* shf_res=data;
    for(int i = 0;i < n; i++){
        shf_res = shf(shf_res,size);
    }

    return shf_res;
}

bool* rot(bool* data,int size){
    bool * rot_data = new bool[size];
    rot_data[size-1]=data[0];
    for(int i = 1;i < size;i++){
        rot_data[i-1] = data[i];
    }
    return rot_data;
}

bool* shf(bool* data,int size){
    bool * shf_data = new bool[size];
    for(int i = 1;i < size;i++){
        shf_data[i-1] = data[i];
    }
    shf_data[size-1]=0;
    return shf_data;
}

bool* xor_array(const bool* first_bool_array,const bool* second_bool_array, int size){
    bool* xor_data = new bool[size];
    for(int i = 0; i < size; i++){
        xor_data[i] = first_bool_array[i]!=second_bool_array[i];
    }
    return xor_data;
}

bool* and_array(const bool* first_bool_array,const bool* second_bool_array, int size){
    bool* xor_data = new bool[size];
    for(int i = 0; i < size; i++){
        xor_data[i] = first_bool_array[i]&&second_bool_array[i];
    }
    return xor_data;
}

bool* add_array(const bool* first_bool_array,const bool* second_bool_array, int size){
    bool* add_data = new bool[size];
    bool c = 0;
    for(int i = 0; i < size; i++){
        add_data[i] = first_bool_array[i]!=second_bool_array[i]!=c;
        c = (first_bool_array[i] && second_bool_array[i]) || (first_bool_array[i]&&c) || (c&&second_bool_array[i]);
    }
    return add_data;
}

bool* not_array(const bool* bool_array, int size){
    bool* not_data = new bool[size];
    for(int i = 0; i < size; i++){
        not_data[i] = !bool_array[i];
    }
    return not_data;
}

bool* twos_comp_array(const bool* bool_array, int size){
    bool* one = new bool[size];
    for(int i = 1; i < size; i++) one[i] = 0;
    one[0] = 1;
    return add_array(not_array(bool_array, size), one, size);
}

bool* assign_array(bool* bool_array, const bool* assigner_array, int size, bool initial){
    if(initial) bool_array = new bool[size];
    for(int i = 0; i < size; i++) bool_array[i] = assigner_array[i];
    return bool_array;
}

bool* sigma(bool* data,int size,int first_rot_loop,int second_rot_loop,int shf_loop){
    bool* rot_first_result=data;
    for(int i = 0;i < first_rot_loop; i++){
        rot_first_result = rot(rot_first_result,size);
    }
    bool* rot_second_result=data;
    for(int i = 0;i < second_rot_loop; i++){
        rot_second_result = rot(rot_second_result,size);
    }
    bool* shf_result=data;
    for(int i = 0;i < shf_loop; i++){
        shf_result = shf(shf_result,size);
    }
    return xor_array(xor_array(rot_first_result,rot_second_result,size),shf_result,size);
}


bool* sigma_zero(bool* data,int size){
    return sigma(data,size,17,14,12);
}

bool* sigma_one(bool* data,int size){
    return sigma(data,size,9,19,9);
}

bool* /*32*/ convert_hexa_2_bool(string hex){
    bool* ret = new bool [32];
    for(int i = 0; i < 8; i++){
        array<bool, 4> dig = convert_hexa_digit__2_bool(hex[i]);
        for(int j = 0; j < 4; j++)
        {
            ret[i*4+j] = dig[j];
        }
    }
    return &ret[0];
}

array<bool, 4> convert_hexa_digit__2_bool(char hex){
    switch (hex){
        case '0': return {0,0,0,0};
        case '1': return {0,0,0,1};
        case '2': return {0,0,1,0};
        case '3': return {0,0,1,1};
        case '4': return {0,1,0,0};
        case '5': return {0,1,0,1};
        case '6': return {0,1,1,0};
        case '7': return {0,1,1,1};
        case '8': return {1,0,0,0};
        case '9': return {1,0,0,1};
        case 'a': return {1,0,1,0};
        case 'b': return {1,0,1,1};
        case 'c': return {1,1,0,0};
        case 'd': return {1,1,0,1};
        case 'e': return {1,1,1,0};
        case 'f': return {1,1,1,1};
        default:  return {0,0,0,0};
    }
}


bool** parsing_w(bool* data,int data_size){
    bool ** w_blocks = new bool*[64];
    for(int i = 0;i < data_size;i++){
        if(i % 32 == 0){
            w_blocks[i/32] = new bool[32];
        }
        w_blocks[i/32][i%32] = data[i];
    }
    for(int i=16; i < 64; i++){
        w_blocks[i] = add_array(
                add_array(
                        sigma_one(w_blocks[i-1],32),
                        w_blocks[i-6],
                        32
                ),
                add_array(
                        sigma_zero(w_blocks[i-12],32),
                        w_blocks[i-15],
                        32
                ),
                32
        );
    }
    return w_blocks;

}

bool** permutation(bool** data){
    bool** permutation_data = new bool*[64];
    for(int i = 0; i < 64; i++){
        permutation_data[i] = new bool[32];
        for(int j = 0; j < 32; j++){
            int current_block = 3-(j/8);
            permutation_data[i][current_block*8 + (7-j%8)] = data[i][j];
        }
    }
    return permutation_data;
}

