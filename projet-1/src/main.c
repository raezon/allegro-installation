#include <allegro5/allegro.h>  // Allegro principal
#include <allegro5/allegro_primitives.h>  // Primitives pour dessiner des formes// Pour gérer les événements clavier
#include <stdio.h>  // Pour fprintf

int main() {
    // Initialisation d'Allegro
    if (!al_init()) {
        fprintf(stderr, "Échec de l'initialisation d'Allegro\n");
        return -1;
    }

    // Initialisation des primitives
    if (!al_init_primitives_addon()) {
        fprintf(stderr, "Échec de l'initialisation des primitives\n");
        return -1;
    }

    // Initialisation du clavier
    if (!al_install_keyboard()) {
        fprintf(stderr, "Échec de l'installation du clavier\n");
        return -1;
    }

    // Création de la fenêtre
    ALLEGRO_DISPLAY *display = al_create_display(800, 600);
    if (!display) {
        fprintf(stderr, "Échec de la création de la fenêtre\n");
        return -1;
    }

    // Création de la queue d'événements
    ALLEGRO_EVENT_QUEUE *queue = al_create_event_queue();
    if (!queue) {
        fprintf(stderr, "Échec de la création de la queue d'événements\n");
        return -1;
    }

    // Enregistrer les événements du clavier
    al_register_event_source(queue, al_get_keyboard_event_source());

    // Couleur rouge pour la boule
    ALLEGRO_COLOR red = al_map_rgb(255, 0, 0);

    // Position initiale de la boule
    float ball_x = 400, ball_y = 300;

    // Boucle principale
    bool running = true;
    while (running) {
        ALLEGRO_EVENT ev;
        al_wait_for_event(queue, &ev);  // Attendre un événement

        // Vérifier si un événement de touche a été pressée
        if (ev.type == ALLEGRO_EVENT_KEYDOWN) {
            // Déplacer la boule en fonction de la touche enfoncée
            if (ev.keyboard.keycode == ALLEGRO_KEY_UP) {
                ball_y -= 5;  // Déplacer vers le haut
            } else if (ev.keyboard.keycode == ALLEGRO_KEY_DOWN) {
                ball_y += 5;  // Déplacer vers le bas
            } else if (ev.keyboard.keycode == ALLEGRO_KEY_LEFT) {
                ball_x -= 5;  // Déplacer vers la gauche
            } else if (ev.keyboard.keycode == ALLEGRO_KEY_RIGHT) {
                ball_x += 5;  // Déplacer vers la droite
            }
            // Quitter si la touche "Échap" est pressée
            else if (ev.keyboard.keycode == ALLEGRO_KEY_ESCAPE) {
                running = false;
            }
        }

        // Effacer l'écran et redessiner la boule
        al_clear_to_color(al_map_rgb(255, 255, 255));  // Effacer l'écran avec du blanc
        al_draw_filled_circle(ball_x, ball_y, 20, red);  // Dessiner la boule rouge
        al_flip_display();  // Rafraîchir l'affichage
    }

    // Nettoyage et fermeture
    al_destroy_event_queue(queue);
    al_destroy_display(display);

    return 0;
}
