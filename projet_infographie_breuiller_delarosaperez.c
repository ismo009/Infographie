/*Fair par Julian BREUILLER et Ismael DE LA ROSA PÉREZ - Projet Infographie*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <stdbool.h>
#include <string.h>

#define POINTS_MAX 20
#define LARGEUR 2000
#define HAUTEUR 1432
#define COULEUR_COURBE 0, 0, 0

typedef struct {
    int x;
    int y;
} COORD;

int donnees[][2] = {
        {7, 644},
        {-4, 636},
        {6, 590},
        {29, 560},
        {47, 530},
        {48, 490},
        {78, 470},
        {106, 449},
        {139, 420},
        {131, 383},
        {133, 364},
        {131, 351},
        {112, 365},
        {88, 370},
        {115, 341},
        {105, 325},
        {110, 286},
        {160, 286},
        {189, 275},
        {251, 270},
        {317, 287},
        {379, 268},
        {409, 259},
        {441, 250},
        {471, 266},
        {497, 278},
        {526, 287},
        {551, 274},
        {540, 261},
        {534, 231},
        {559, 247},
        {572, 250},
        {605, 268},
        {581, 248},
        {543, 225},
        {485, 228},
        {461, 183},
        {444, 154},
        {452, 121},
        {440, 90},
        {420, 76},
        {399, 32},
        {424, 24},
        {416, 47},
        {453, 96},
        {450, 48},
        {449, 26},
        {469, 17},
        {463, 44},
        {460, 58},
        {467, 100},
        {470, 65},
        {470, 48},
        {480, -3},
        {498, 4},
        {493, 24},
        {478, 55},
        {490, 69},
        {501, 55},
        {515, 18},
        {533, 23},
        {520, 40},
        {488, 91},
        {536, 78},
        {570, 67},
        {537, 100},
        {518, 92},
        {478, 89},
        {467, 134},
        {478, 164},
        {488, 200},
        {530, 206},
        {561, 218},
        {587, 232},
        {598, 210},
        {591, 187},
        {589, 170},
        {621, 121},
        {616, 163},
        {600, 176},
        {612, 225},
        {629, 192},
        {629, 181},
        {627, 136},
        {642, 169},
        {644, 186},
        {645, 213},
        {661, 183},
        {682, 163},
        {663, 214},
        {650, 212},
        {633, 218},
        {585, 232},
        {624, 242},
        {651, 257},
        {667, 218},
        {679, 213},
        {677, 227},
        {667, 267},
        {690, 242},
        {710, 253},
        {667, 267},
        {687, 279},
        {671, 293},
        {622, 240},
        {625, 275},
        {645, 303},
        {678, 318},
        {697, 343},
        {700, 357},
        {688, 370},
        {676, 376},
        {651, 369},
        {627, 368},
        {600, 371},
        {577, 375},
        {566, 403},
        {547, 415},
        {521, 433},
        {480, 450},
        {504, 488},
        {529, 541},
        {557, 592},
        {597, 633},
        {627, 653},
        {562, 662},
        {561, 636},
        {537, 633},
        {546, 588},
        {524, 573},
        {502, 537},
        {467, 510},
        {445, 472},
        {442, 449},
        {424, 432},
        {413, 462},
        {389, 507},
        {366, 552},
        {345, 597},
        {331, 619},
        {369, 662},
        {324, 652},
        {303, 640},
        {293, 614},
        {317, 596},
        {342, 562},
        {340, 520},
        {357, 483},
        {373, 460},
        {362, 431},
        {331, 445},
        {300, 457},
        {263, 440},
        {236, 462},
        {213, 483},
        {197, 519},
        {221, 544},
        {245, 579},
        {265, 618},
        {296, 645},
        {289, 656},
        {267, 651},
        {255, 651},
        {228, 633},
        {237, 593},
        {208, 572},
        {195, 547},
        {153, 527},
        {163, 495},
        {172, 482},
        {183, 459},
        {158, 477},
        {134, 496},
        {101, 504},
        {80, 528},
        {61, 558},
        {42, 590},
        {32, 626},
        {55, 648},
        {25, 661}
    };

// Fonction pour calculer et dessiner une courbe de Bézier cubique


//fonction qui dessine un pixel
void dessiner_pixel(int *im, int w, int h, int x, int y, int r, int g, int b) {
    if (x >= 0 && x < w && y >= 0 && y < h) {
        im[(y * w + x) * 3] = r;
        im[(y * w + x) * 3 + 1] = g;
        im[(y * w + x) * 3 + 2] = b;
    }
}

void courbe_bezier_cubique(COORD P0, COORD P1, COORD P2, COORD P3, int num_points, int *im, int w, int h, int r, int g, int b) {
    for (int i = 0; i <= num_points; i++) {
        double t = (double)i / num_points;
        double x = pow(1 - t, 3) * P0.x + 3 * pow(1 - t, 2) * t * P1.x + 
                   3 * (1 - t) * pow(t, 2) * P2.x + pow(t, 3) * P3.x;
        double y = pow(1 - t, 3) * P0.y + 3 * pow(1 - t, 2) * t * P1.y + 
                   3 * (1 - t) * pow(t, 2) * P2.y + pow(t, 3) * P3.y;
        
        int px = (int)x;
        int py = (int)y;
        if (px >= 0 && px < w && py >= 0 && py < h) {
            int index = (py * w + px) * 3;
            float alpha = 1; // 50% transparence
            im[index] = (int)(alpha * r + (1 - alpha) * im[index]);
            im[index + 1] = (int)(alpha * g + (1 - alpha) * im[index + 1]);
            im[index + 2] = (int)(alpha * b + (1 - alpha) * im[index + 2]);
        }
    }
}

// dessine un segment
void tracer_segment(int x1, int y1, int x2, int y2, int *im, int w, int h, int r, int g, int b) {
    int dx = abs(x2 - x1), dy = abs(y2 - y1);
    int sx = (x1 < x2) ? 1 : -1;
    int sy = (y1 < y2) ? 1 : -1;
    int err = dx - dy;

    while (1) {
        dessiner_pixel(im, w, h, x1, y1, r, g, b);
        if (x1 == x2 && y1 == y2) break;
        int e2 = 2 * err;
        if (e2 > -dy) { err -= dy; x1 += sx; }
        if (e2 < dx) { err += dx; y1 += sy; }
    }
}

// Remplir le polygone en utilisant un algorithme de balayage avec transparence
void remplir_polygone(COORD points[], int nb_points, int *im, int w, int h, int r, int g, int b, float transparence) {
    int ymin = h, ymax = 0;

    // Trouver les limites verticales du polygone
    for (int i = 0; i < nb_points; i++) {
        if (points[i].y < ymin) ymin = points[i].y;
        if (points[i].y > ymax) ymax = points[i].y;
    }

    // Balayer chaque ligne horizontale
    for (int y = ymin; y <= ymax; y++) {
        int intersections[POINTS_MAX];
        int count = 0;

        // Trouver les intersections du polygone avec la ligne de balayage
        for (int i = 0; i < nb_points; i++) {
            COORD p1 = points[i];
            COORD p2 = points[(i + 1) % nb_points]; // Boucler vers le premier point

            if ((p1.y <= y && p2.y > y) || (p1.y > y && p2.y <= y)) {
                int x = p1.x + (y - p1.y) * (p2.x - p1.x) / (p2.y - p1.y);
                intersections[count++] = x;
            }
        }

        // Trier les intersections par coordonnée x
        for (int i = 0; i < count - 1; i++) {
            for (int j = i + 1; j < count; j++) {
                if (intersections[i] > intersections[j]) {
                    int temp = intersections[i];
                    intersections[i] = intersections[j];
                    intersections[j] = temp;
                }
            }
        }

        // Remplir entre les paires d'intersections
        for (int i = 0; i < count; i += 2) {
            if (i + 1 < count) {
                for (int x = intersections[i]; x <= intersections[i + 1]; x++) {
                    int index = (y * w + x) * 3;
                    im[index] = (int)(transparence * r + (1 - transparence) * im[index]);
                    im[index + 1] = (int)(transparence * g + (1 - transparence) * im[index + 1]);
                    im[index + 2] = (int)(transparence * b + (1 - transparence) * im[index + 2]);
                }
            }
        }
    }
}

// Remplir le polygone avec un dégradé et transparence
void remplir_polygone_degrade(COORD points[], int nb_points, int *im, int w, int h, 
                              int r_etoilet, int g_etoilet, int b_etoilet, 
                              int r_end, int g_end, int b_end, float transparence) {
    int ymin = h, ymax = 0;

    // Trouver les limites verticales du polygone
    for (int i = 0; i < nb_points; i++) {
        if (points[i].y < ymin) ymin = points[i].y;
        if (points[i].y > ymax) ymax = points[i].y;
    }

    // Balayer chaque ligne horizontale
    for (int y = ymin; y <= ymax; y++) {
        int intersections[POINTS_MAX];
        int count = 0;

        for (int i = 0; i < nb_points; i++) {
            COORD p1 = points[i];
            COORD p2 = points[(i + 1) % nb_points];

            if ((p1.y <= y && p2.y > y) || (p1.y > y && p2.y <= y)) {
                int x = p1.x + (y - p1.y) * (p2.x - p1.x) / (p2.y - p1.y);
                intersections[count++] = x;
            }
        }

        for (int i = 0; i < count - 1; i++) {
            for (int j = i + 1; j < count; j++) {
                if (intersections[i] > intersections[j]) {
                    int temp = intersections[i];
                    intersections[i] = intersections[j];
                    intersections[j] = temp;
                }
            }
        }

        for (int i = 0; i < count; i += 2) {
            if (i + 1 < count) {
                for (int x = intersections[i]; x <= intersections[i + 1]; x++) {
                    float t = (float)(y - ymin) / (ymax - ymin);
                    int r = (int)(r_etoilet * (1 - t) + r_end * t);
                    int g = (int)(g_etoilet * (1 - t) + g_end * t);
                    int b = (int)(b_etoilet * (1 - t) + b_end * t);

                    int index = (y * w + x) * 3;
                    im[index] = (int)(transparence * r + (1 - transparence) * im[index]);
                    im[index + 1] = (int)(transparence * g + (1 - transparence) * im[index + 1]);
                    im[index + 2] = (int)(transparence * b + (1 - transparence) * im[index + 2]);
                }
            }
        }
    }
}

void batiment(int x, int y, int hauteur, int largeur, int *im, int w, int h, int r, int g, int b, float transparence) {
    COORD points[4] = {{x, y}, {x + largeur, y}, {x + largeur, y + hauteur}, {x, y + hauteur}};
    remplir_polygone(points, 4, im, w, h, r, g, b, transparence);

    int num_fenetre_x = (rand() % (largeur / 30) + 1)*1.75;
    int num_fenetre_y = (rand() % (hauteur / 30) + 1)*1.75;

    int fenetre_espacement_x = largeur / (num_fenetre_x + 1);
    int fenetre_espacement_y = hauteur / (num_fenetre_y + 1);

    for (int i = 0; i < num_fenetre_x; i++) {
        for (int j = 0; j < num_fenetre_y; j++) {
            if (rand() % 4 == 0) continue;

            int largeur_fenetre = rand() % (fenetre_espacement_x - 10) + 10 ;
            int hauteur_fenetre = rand() % (fenetre_espacement_y - 10) + 10;

            int fenetre_x = x + fenetre_espacement_x * i + (fenetre_espacement_x - largeur_fenetre) / 2;
            int fenetre_y = y + fenetre_espacement_y * j + (fenetre_espacement_y - hauteur_fenetre) / 2+15;

            COORD points_fenetre[4] = {{fenetre_x, fenetre_y}, {fenetre_x + largeur_fenetre, fenetre_y}, 
                                      {fenetre_x + largeur_fenetre, fenetre_y + hauteur_fenetre}, {fenetre_x, fenetre_y + hauteur_fenetre}};

            remplir_polygone(points_fenetre, 4, im, w, h, 200, 200, 25, transparence);
        }
    }
}
bool** creerVisite(int w, int h) {
    bool** visite = malloc(h * sizeof(bool*));
    for (int i = 0; i < h; i++) {
        visite[i] = calloc(w, sizeof(bool));
    }
    return visite;
}

void libererVisite(bool** visite, int h) {
    for (int i = 0; i < h; i++) {
        free(visite[i]);
    }
    free(visite);
}
void remplissage_par_diffusion(int *im, int w, int h, int debut_x, int debut_y, int nouveau_r, int nouveau_g, int nouveau_b) {
    // Couleur cible à remplacer
    int cible_r = im[(debut_y * w + debut_x) * 3];
    int cible_g = im[(debut_y * w + debut_x) * 3 + 1];
    int cible_b = im[(debut_y * w + debut_x) * 3 + 2];

    // Si la couleur cible est déjà la nouvelle couleur, rien à faire
    if (cible_r == nouveau_r && cible_g == nouveau_g && cible_b == nouveau_b) {
        return;
    }

    // Création d'une matrice pour suivre les pixels visités
    bool** visite = creerVisite(w, h);
    if (!visite) {
        fprintf(stderr, "Erreur : allocation mémoire pour visite\n");
        return;
    }

    // Création d'une pile pour les pixels à traiter
    COORD *pile = malloc(w * h * sizeof(COORD)); // Taille maximale théorique
    if (!pile) {
        fprintf(stderr, "Erreur : allocation mémoire pour la pile\n");
        libererVisite(visite, h);
        return;
    }
    int pile_taille = 0;

    // Ajouter le point de départ à la pile
    pile[pile_taille++] = (COORD){debut_x, debut_y};

    // Fonction pour comparer les couleurs avec tolérance
    #define EST_COULEUR_CIBLE(r, g, b) (abs(r - cible_r) < 50 && abs(g - cible_g) < 50 && abs(b - cible_b) < 50)
    #define EST_CONTOUR(r, g, b) (r == 243 && g == 212 && b == 196)

    // Parcourir les pixels de la pile
    while (pile_taille > 0) {
        // Récupérer un pixel de la pile
        COORD courant = pile[--pile_taille];
        int x = courant.x;
        int y = courant.y;

        // Vérifier si le pixel est dans les limites
        if (x < 0 || x >= w || y < 0 || y >= h || visite[y][x]) {
            continue;
        }

        // Marquer le pixel comme visité
        visite[y][x] = true;

        // Vérifier si le pixel est noir (limite de la forme)
        int index = (y * w + x) * 3;
        int r = im[index];
        int g = im[index + 1];
        int b = im[index + 2];
        if (EST_CONTOUR(r, g, b)) {
            continue;
        }

        // Vérifier si la couleur correspond à la cible
        if (EST_COULEUR_CIBLE(255, 255, 255)) {
            // Modifier la couleur du pixel
            float alpha = 0.3; // 50% transparency
            im[index] = (int)(alpha * nouveau_r + (1 - alpha) * im[index]);
            im[index + 1] = (int)(alpha * nouveau_g + (1 - alpha) * im[index + 1]);
            im[index + 2] = (int)(alpha * nouveau_b + (1 - alpha) * im[index + 2]);
            // Ajouter les pixels voisins à la pile
            pile[pile_taille++] = (COORD){x + 1, y};
            pile[pile_taille++] = (COORD){x - 1, y};
            pile[pile_taille++] = (COORD){x, y + 1};
            pile[pile_taille++] = (COORD){x, y - 1};
        }
    }

    // Nettoyer la mémoire
    free(pile);
    libererVisite(visite, h);
}


int main() {

    srand(56);
    int w = 2000, h = 1432;
    int *im = malloc(w * h * 3 * sizeof(int));
    if (im == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }
    char output[20];
    sprintf(output, "output%d.ppm", 56);
    FILE *f = fopen(output, "w");
    if (f == NULL) {
        fprintf(stderr, "Failed to open file\n");
        free(im);
        return 1;
    }
    fprintf(f, "P3\n%d %d\n255\n", w, h);

    for (int y = 0; y < h; y++) {
        for (int x = 0; x < w; x++) {
            im[(y * w + x) * 3] = 20;
            im[(y * w + x) * 3 + 1] = 20;
            im[(y * w + x) * 3 + 2] = 20;
        }
    }

    COORD points_ciel[4] = {{0, 0}, {w, 0}, {w, h}, {0, h}};
    remplir_polygone_degrade(points_ciel, 4, im, w, h, 0, 0, 0, 125, 60, 130, 1.0);

    int parametres_batiment[][4] = {
        {82, 123, 1309, 257},
        {502, 487, 945, 202}, 
        {1294, 797, 635, 160},
        {1888, 567, 865, 112},
        {1491, 873, 559, 258},
        {567, 727, 705, 243},
        {121, 632, 800, 162},
        {0, 765, 667, 206},
        {235, 851, 581, 194}, 
        {810, 594, 838, 230},
        {1767, 690, 742, 233},
        {916, 739, 693, 321},
        {1646, 1025, 407, 218},
        {1204, 1244, 188, 578},
        {446, 1052, 380, 301},
        {0, 1224, 208, 521}
    };

    for (int i = 0; i < 16; i++) {
        batiment(parametres_batiment[i][0], parametres_batiment[i][1], parametres_batiment[i][2], parametres_batiment[i][3], im, w, h, 0, 0, 0, 0.3+0.046*i);
    }

    int num_etoiles = 400;
    for (int i = 0; i < num_etoiles; i++) {
        int etoile_x = rand() % w;
        int etoile_y = rand() % h;
        while (etoile_y > 700) {
            etoile_x = rand() % w;
            etoile_y = rand() % h;
        }
        int etoile_luminosite = rand() % 156 + 100; // luminosité entre 100 et 255
        dessiner_pixel(im, w, h, etoile_x, etoile_y, etoile_luminosite, etoile_luminosite, etoile_luminosite);
    }

    // dessiner la lune
    int lune_centre_x = 1500;
    int lune_centre_y = 400;
    int lune_rayon = 300;
    for (int y = lune_centre_y - lune_rayon; y <= lune_centre_y + lune_rayon; y++) {
        for (int x = lune_centre_x - lune_rayon; x <= lune_centre_x + lune_rayon; x++) {
            int dx = x - lune_centre_x;
            int dy = y - lune_centre_y;
            if (dx * dx + dy * dy <= lune_rayon * lune_rayon) {
                float distance = sqrt(dx * dx + dy * dy);
                float t = distance / lune_rayon;
                int r = (int)(255 * (1 - t) + 255 * t*0.9);
                int g = (int)(255 * (1 - t) + 255 * t*0.9);
                int b = (int)(255 * (1 - t) + 200 * t*0.9);
                dessiner_pixel(im, w, h, x, y, r, g, b);
            }
        }
    }

    // dessiner la courbe de Bézier

    
    for (int i = 0; i < 180; i += 3) {
        COORD P0 = {donnees[i][0]*0.7+1276,donnees[i][1]*0.7+150};
        COORD P1 = {donnees[i + 1][0]*0.7+1276,donnees[i + 1][1]*0.7+150};
        COORD P2 = {donnees[i + 2][0]*0.7+1276,donnees[i + 2][1]*0.7+150};
        COORD P3 = {donnees[i + 3][0]*0.7+1276,donnees[i + 3][1]*0.7+150}; 
        courbe_bezier_cubique(P0, P1, P2, P3, 150, im, LARGEUR, HAUTEUR,243, 212, 196);
    }
    COORD P0 = {donnees[177][0]*0.7+1276, donnees[177][1]*0.7+150};
    COORD P1 = {donnees[178][0]*0.7+1276, donnees[178][1]*0.7+150};
    COORD P2 = {donnees[179][0]*0.7+1276, donnees[179][1]*0.7+150};
    COORD P3 = {donnees[0][0]*0.7+1276, donnees[0][1]*0.7+150};
    courbe_bezier_cubique(P0, P1, P2, P3, 150, im, LARGEUR, HAUTEUR, 243, 212, 196);

    // remplir le polygone avec une couleur de dégradé    
    remplissage_par_diffusion(im, LARGEUR, HAUTEUR, 1488, 416, 255, 150, 171);  


    // écrire l'image dans le fichier
    for (int y = 0; y < h; y++) {
        for (int x = 0; x < w; x++) {
            fprintf(f, "%d %d %d ", im[(y * w + x) * 3], im[(y * w + x) * 3 + 1], im[(y * w + x) * 3 + 2]);
        }
        fprintf(f, "\n");
    }



    fclose(f);
    free(im);
    

    return 0;
}
