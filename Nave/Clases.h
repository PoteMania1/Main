//Declaracion de clases


class aeronave{
    private:
        int x,y;
    public:
        aeronave(int _x, int _y): x(_x), y(_y){}
        void pintar();
        void borrar();
        void mover();
};
