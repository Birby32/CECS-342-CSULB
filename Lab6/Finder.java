package Lab6;

public class Finder implements Runnable {
    monitorThread t;
    int start;
    int key;
    Finder(int start,int key,monitorThread t){
        this.start = start;
        this.key = key;
        this.t = t;
    }

    public void run(){
        try {
            System.out.println("Finding Number");
            for(int i = start; i < start+ 250;i++){
                if(i == key){
                    t.FoundNumber();
                    System.out.println("Thread"+t.getName() +"Stopping");
                    System.out.println("Found value "+i+" in thread.");
                }
            }
        }
        catch (Exception e) {
            // Throwing an exception
            System.out.println("Exception is caught");
        }
    }
}
