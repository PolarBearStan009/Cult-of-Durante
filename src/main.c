#include <stdio.h>
#include <string.h>

typedef struct {
    int sanity;       // 0-100
    int manipulation; // 0-100
    int scene;        // current scene id
    int running;
} Player;

static void print_stats(const Player *p) {
    printf("[ Sanity: %d | Manipulation: %d ]\n\n", p->sanity, p->manipulation);
}

static int read_choice(void) {
    char line[64];
    int choice;
    if (!fgets(line, sizeof(line), stdin)) return -1;
    if (sscanf(line, "%d", &choice) != 1) return -1;
    return choice;
}

/* Each scene_* function prints the scene, takes input, and sets p->scene
 * to the next scene id based on the player's choice. */

static void scene_intro(Player *p) {
    printf("You wake up in a cold apartment. The city outside hums with noise.\n");
    printf("A voice in your head tells you the world is a game, and everyone else is a piece.\n\n");
    printf("1) Get up and look around\n");
    printf("2) Stay in bed and think\n> ");

    int choice = read_choice();
    if (choice == 1) {
        p->scene = 1;
    } else if (choice == 2) {
        p->sanity -= 5;
        p->scene = 1;
    } else {
        printf("\nInvalid choice.\n\n");
    }
}

static void scene_placeholder(Player *p) {
    printf("(No more story written yet. Waiting on the next scene...)\n");
    p->running = 0;
}

int main(void) {
    Player p = { .sanity = 100, .manipulation = 10, .scene = 0, .running = 1 };

    printf("=== Cult of Durante ===\n\n");

    while (p.running) {
        print_stats(&p);
        switch (p.scene) {
            case 0: scene_intro(&p); break;
            default: scene_placeholder(&p); break;
        }
        printf("\n");
    }

    return 0;
}
