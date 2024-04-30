typedef struct cep Cep;
typedef struct no No;
typedef No* Apont;
typedef Apont Dic;

void criarArvore(Apont *x);
void insereArvore(Apont *p);
void retiraArvore(Cep x, Apont *p);
void Antecessor(Apont *q, Apont *r);
Cep* pesquisaArvore(const char* x, Apont *p);
void Central(Apont *p);
void PreFixado(Apont *p);
void PosFixado(Apont *p);
int achaAltura(Apont *p);
Cep* maiorElemArvore(Apont *p);
Cep* menorElemArvore(Apont *p);
void insereArvore20(Apont *p);

