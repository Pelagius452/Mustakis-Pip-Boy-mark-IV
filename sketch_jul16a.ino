#include <bb_spi_lcd.h>
BB_SPI_LCD lcd;

// Variables para el estado actual
int currentWindow = 0;

// Función para mostrar la ventana correspondiente
void displayWindow(int window);

// Función para mostrar la interfaz principal de Pip-Boy
void displayPipBoyInterface();

// Función para dibujar los bordes de la interfaz
void drawBorders();

// Función para mostrar información de estado (ejemplo)
void displayStatus();

// Función para mostrar la ventana de inventario
void displayInventory();

// Función para mostrar la ventana de estadísticas
void displayStats();

// Función para mostrar la ventana del mapa
void displayMap();

// Función para mostrar la ventana de configuración
void displaySettings();

void setup() {
  lcd.begin(DISPLAY_CYD_2USB); // initialize the LCD
  lcd.setRotation(1); // Rotar la pantalla para orientación horizontal
  lcd.fillScreen(TFT_BLACK);
  lcd.setFont(FONT_12x16);
  lcd.setTextColor(TFT_GREEN, TFT_BLACK);
  lcd.println("CYD LCD & Touch Test");
  lcd.rtInit(); // initialize the resistive touch controller

  displayWindow(currentWindow);
}

void loop() {
  TOUCHINFO ti;
  lcd.rtReadTouch(&ti);
  
  if (ti.count > 0) {
    int touchX = ti.x[0];
    int touchY = ti.y[0];
    
    // Determinar qué ventana se debe mostrar basada en la posición táctil
    if (touchY < 48) {
      currentWindow = 0;
    } else if (touchY < 96) {
      currentWindow = 1;
    } else if (touchY < 144) {
      currentWindow = 2;
    } else if (touchY < 192) {
      currentWindow = 3;
    } else {
      currentWindow = 4;
    }

    displayWindow(currentWindow);
  }
}

void displayWindow(int window) {
  lcd.fillScreen(TFT_BLACK); // Limpiar la pantalla

  switch (window) {
    case 0:
      displayPipBoyInterface();
      break;
    case 1:
      displayInventory();
      break;
    case 2:
      displayStats();
      break;
    case 3:
      displayMap();
      break;
    case 4:
      displaySettings();
      break;
  }
}

void displayPipBoyInterface() {
  lcd.setTextSize(2);
  lcd.setTextColor(TFT_GREEN);
  lcd.setCursor(90, 10);
  lcd.println("Pip-Boy 3000");

  drawBorders();
  displayStatus();
}

void drawBorders() {
  lcd.drawRect(10, 40, 200, 300, TFT_GREEN); // Marco principal
  lcd.drawRect(20, 60, 60, 280, TFT_GREEN); // Sección superior
  lcd.drawRect(20, 130, 100, 280, TFT_GREEN); // Sección inferior
}

void displayStatus() {
  lcd.setTextSize(1);
  lcd.setCursor(30, 70);
  lcd.println("HP: 85/100");
  lcd.setCursor(30, 90);
  lcd.println("AP: 45/50");
  lcd.setCursor(30, 110);
  lcd.println("RAD: 0");

  lcd.setCursor(30, 140);
  lcd.println("Inventory:");
  lcd.setCursor(30, 160);
  lcd.println("- Stimpak x3");
  lcd.setCursor(30, 180);
  lcd.println("- RadAway x2");
  lcd.setCursor(30, 200);
  lcd.println("- Caps x50");
  lcd.setCursor(30, 220);
  lcd.println("- Ammo x200");
}

void displayInventory() {
  lcd.setTextSize(2);
  lcd.setTextColor(TFT_GREEN);
  lcd.setCursor(120, 10);
  lcd.println("Inventory");

  lcd.setTextSize(1);
  lcd.setCursor(30, 50);
  lcd.println("- Stimpak x3");
  lcd.setCursor(30, 70);
  lcd.println("- RadAway x2");
  lcd.setCursor(30, 90);
  lcd.println("- Caps x50");
  lcd.setCursor(30, 110);
  lcd.println("- Ammo x200");
}

void displayStats() {
  lcd.setTextSize(2);
  lcd.setTextColor(TFT_GREEN);
  lcd.setCursor(140, 10);
  lcd.println("Stats");

  lcd.setTextSize(1);
  lcd.setCursor(30, 50);
  lcd.println("Strength: 7");
  lcd.setCursor(30, 70);
  lcd.println("Perception: 5");
  lcd.setCursor(30, 90);
  lcd.println("Endurance: 8");
  lcd.setCursor(30, 110);
  lcd.println("Charisma: 6");
  lcd.setCursor(30, 130);
  lcd.println("Intelligence: 7");
  lcd.setCursor(30, 150);
  lcd.println("Agility: 9");
  lcd.setCursor(30, 170);
  lcd.println("Luck: 4");
}

void displayMap() {
  lcd.setTextSize(2);
  lcd.setTextColor(TFT_GREEN);
  lcd.setCursor(170, 10);
  lcd.println("Map");

  lcd.setTextSize(1);
  lcd.setCursor(30, 50);
  lcd.println("Map functionality");
  lcd.setCursor(30, 70);
  lcd.println("coming soon...");
}

void displaySettings() {
  lcd.setTextSize(2);
  lcd.setTextColor(TFT_GREEN);
  lcd.setCursor(120, 10);
  lcd.println("Settings");

  lcd.setTextSize(1);
  lcd.setCursor(30, 50);
  lcd.println("Brightness: 70%");
  lcd.setCursor(30, 70);
  lcd.println("Volume: 50%");
}
