int main()
{
    int i = 10;
    {
        int *pi = new int{i};
        (*pi) = 17;  // va à l'objet qui est à cette adresse
        delete pi; // on enlève la zone mémoire
        *pi = 22;  // on va sur une zone qui a été détruite (au pire il se passe rien)
    }
    return 0;
}