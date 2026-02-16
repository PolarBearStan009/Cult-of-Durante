
public class Main {
   private boolean running = true;
   private Scanner scanner;
   private int sanity;
   private int manipulation;

   public Main() {
      this.scanner = new Scanner(System.in);
      this.sanity = 100;
      this.manipulation = 0;
   }

   public void start() {
      System.out.println("Welcome to the Psychopath RPG.");
      System.out.println("Type 'help' for commands, 'quit' to exit.");

      while(this.running) {
         System.out.print("> ");
         if (!this.scanner.hasNextLine()) {
            break;
         }

         String var1 = this.scanner.nextLine().trim();
         this.processInput(var1);
      }

      this.scanner.close();
      System.out.println("Game Over.");
   }

   private void processInput(String var1) {
      if (!var1.isEmpty()) {
         switch (var1.toLowerCase()) {
            case "help":
               System.out.println("Available commands: look, status, quit");
               break;
            case "status":
               System.out.println("Sanity: " + this.sanity);
               System.out.println("Manipulation: " + this.manipulation);
               break;
            case "look":
               System.out.println("You see a dark room. The air is cold.");
               break;
            case "quit":
               this.running = false;
               break;
            default:
               System.out.println("I don't understand '" + var1 + "'.");
         }

      }
   }

   public static void main(String[] var0) {
      Main var1 = new Main();
      var1.start();
   }
}
