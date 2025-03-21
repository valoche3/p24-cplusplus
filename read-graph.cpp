#include <iostream>
#include <fstream>
#include <string>

// deux fonctions pour lire un graphe dans un fichier

// dans la première le graphe contient une suite de triplets: from1 to1 value1 from2 to2 value2 ... fromN toN valueN
// voir fichier graph0.gr

// dans la seconde le graphe contient un triplet par ligne
// voir fichier graph1.gr

// notons que la première fonction lit les deux sortes de graphes

void read_triplet(const std::string &filename)
{
    std::cout << "read_triplet(" << filename << ")" << std::endl;

    // on essaie d'ouvrir le fichier en lecture
    // pour cela on crée un objet de type std::ifstream (input file stream) et le constructeur ouvre le fichier
    std::ifstream file(filename);

    if (not file.is_open())
    {
        // si le fichier n'a pas pu être ouvert, on s'en va, par exemple en faisant:
        std::cout << "file " << filename << " not found" << std::endl;
        return;
        // on aurait aussi pu lancer une exception
    }

    // si on est arrivé là c'est que le fichier est ouvert, on va le lire
    // on sait qu'il contient le graphe sur une ligne sous la forme de triplets: from to value
    // e.g. Paris Lyon 100 Paris Nice 200 Paris ...

    // from, to sont des strings et value un int
    // on réserve trois variables pour lire ces valeurs
    std::string from, to;
    int value;

    while (file >> from >> to >> value) // tant qu'on a un triplet (les 2 strings et l'int) à lire
    // notons que l'expression "file >> var" a comme valeur l'état du fichier après la lecture de var
    {

        std::cout << from << " " << to << " " << value << std::endl;
        // là on l'affiche simplement l'arête, mais il faudra construire le graphe
    }
    std::cout << std::endl;

    file.close(); // on ferme le fichier

    // MAIS attention si vous mettez un nom de ville avec un espace (même si vous mettez des " " autour) ça plantera
    // puisque quand une std::string est lue, la lecture se fait jusqu'au premier espace
    // donc si vous mettez "Le Havre" ça plantera il faudra mettre Le_Havre (Le Havre fait aussi deux mots)
    // oui c'est nul mais gérer les espaces dans les std::string c'est très compliqué donc n'en mettez pas !
}

#include <sstream>
void read_one_triplet_per_line(const std::string &filename)
{
    std::cout << "read_one_triplet_per_line(" << filename << ")" << std::endl;

    // on peut aussi lire toute la ligne toute entière (le problème Le_Havre reste entier)
    // on utilise std::getline puis on lit le triplet de la std::string avec le type std::istringstream

    std::ifstream file;
    file.open(filename);

    if (not file.is_open())
    {
        // si le fichier n'a pas pu être ouvert, on s'en va, par exemple en faisant:
        std::cout << "file " << filename << " not found" << std::endl;
        return;
        // on aurait aussi pu lancer une exception
    }

    std::string from, to;
    int value;

    // cette fois il nous faut une ligne
    std::string line;
    while (std::getline(file, line))
    {
        // notez on ne fait pas line = aux_file.getline() mais std::getline(aux_file, line)
        // std::getline renvoie un booléen qui est vrai si la lecture d'une ligne a réussi
        std::cout << "ligne lue: " << line << std::endl;

        // on va chercher les trois valeurs dans la std::string en utilisant le type std::istringstream
        // (input string stream) qui lui lit les valeurs (séparées par des espaces aussi)

        std::istringstream iss(line);
        iss >> from >> to >> value;
        std::cout << from << " " << to << " " << value << std::endl;
    }
    file.close(); // on ferme le fichier
}

int main()
{
    read_triplet("./graph0.gr");
    read_triplet("./graph1.gr");

    read_one_triplet_per_line("./graph1.gr");

    return 0;
}
