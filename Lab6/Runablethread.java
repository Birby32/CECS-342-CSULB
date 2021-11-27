package Lab6;

public class Runablethread implements Runnable{
    int start;
    int key;
    Runablethread (int start,int key){
        this.start = start;
        this.key = key;
    }

    public void run(){
        try {
            for(int i = start; i < start+ 250;i++){
                if(i == key)
                    System.out.println("Found value "+i+" in thread.");
            }
        }
        catch (Exception e) {
            // Throwing an exception
            System.out.println("Exception is caught");
        }
    }
}
