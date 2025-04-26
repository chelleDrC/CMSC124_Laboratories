// Program Title: Potion Crafting System
// Description: Demonstrates OOP principles (Encapsulation, Inheritance, Method Overloading, Method Overriding)
// Author: Richelle de Arce, Cherlie Palarpalar
// Task Division:
    /* - Richelle de Arce: Designed the Potion class, implemented the brewPotion methods, and created the HealingPotion subclass.
     - Cherlie Palarpalar: Developed the ManaPotion and PoisonPotion subclasses, implemented the main method, and tested the potion brewing and effects.
     - Both: Collaborated on the overall program structure, ensured consistent coding style, and debugged the final implementation. */
// Date: April 26, 2025

import java.util.Scanner;

/**
 * Interface for brewable items.
 * Demonstrates abstraction by defining a contract for brewing potions.
 */
interface Brewable {
    void brewPotion(); // Method overloading: no parameters
    void brewPotion(String ingredient1, String ingredient2); // Method overloading: with parameters
}

/**
 * Main class to run Potion Crafting System.
 * Demonstrates encapsulation by interacting with Potion objects through their public methods.
 */
public class deArce_Palarpalar_PE07 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        System.out.println("Choose a potion (Healing/Mana/Poison): ");
        String potionType = scanner.nextLine();

        // ADDITIONAL FEATURE: Demonstrates polymorphism: Potion reference points to subclass objects
        Potion potion;
        switch (potionType.toLowerCase()) {
            case "healing": potion = new HealingPotion(); break;
            case "mana": potion = new ManaPotion(); break;
            case "poison": potion = new PoisonPotion(); break;
            default: throw new IllegalArgumentException("Invalid potion type!");
        }

        System.out.println("Enter ingredient 1: ");
        String ing1 = scanner.nextLine();
        System.out.println("Enter ingredient 2: ");
        String ing2 = scanner.nextLine();

        try {
            // Demonstrates method overloading: brewPotion with parameters
            potion.brewPotion(ing1, ing2);
            // Demonstrates method overriding: applyEffect is overridden in subclasses
            potion.applyEffect();
        } catch (IllegalArgumentException e) {
            System.err.println("Error: " + e.getMessage());
        }
    }
}

/**
 * Base Potion class
 * Demonstrates encapsulation by using private fields and public methods to access them.
 * Demonstrates inheritance by serving as the parent class for specific potion types.
 */
class Potion implements Brewable {
    private String name; // Encapsulation: private field
    private int potency; // Encapsulation: private field

    public Potion(String name) {
        this.name = name;
        this.potency = 1; // Default potency
    }

    // Basic brewing
    public void brewPotion() {
        System.out.println(name + " potion is brewing using standard ingredients...");
    }

    // Enhanced brewing with validation
    public void brewPotion(String ingredient1, String ingredient2) {
        if (ingredient1 == null || ingredient2 == null || ingredient1.trim().isEmpty() || ingredient2.trim().isEmpty()) {
            throw new IllegalArgumentException("Ingredients cannot be null or empty!");
        }
        System.out.println(name + " potion is brewing with " + ingredient1 + " and " + ingredient2 + "!");
        increasePotency();
    }

    public void applyEffect() {
        System.out.println("Applying generic potion effect...");
    }

    // Encapsulation: private method to modify internal state
    private void increasePotency() {
        potency++;
        System.out.println("Potion potency increased to: " + potency);
    }

    // Encapsulation: protected method to allow subclasses to access potency
    protected int getPotency() {
        return potency;
    }
}

// Subclasses with dynamic effects
// Demonstrates inheritance and method overriding
class HealingPotion extends Potion {
    public HealingPotion() { super("Healing"); }

    @Override
    public void applyEffect() {
        // Method overriding: specific behavior for HealingPotion
        System.out.printf("You feel rejuvenated! Health restored by %d points.\n", getPotency() * 10);
    }
}

class ManaPotion extends Potion {
    public ManaPotion() { super("Mana"); }

    @Override
    public void applyEffect() {
        // Method overriding: specific behavior for ManaPotion
        System.out.printf("Magical energy surges! Mana replenished by %d points.\n", getPotency() * 15);
    }
}

class PoisonPotion extends Potion {
    public PoisonPotion() { super("Poison"); }

    @Override
    public void applyEffect() {
        // Method overriding: specific behavior for PoisonPotion
        System.out.printf("Toxic cloud deals %d damage over time!\n", getPotency() * 5);
    }
}