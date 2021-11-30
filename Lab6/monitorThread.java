package Lab6;

import java.util.ArrayList;

public class monitorThread extends Thread {
    ArrayList<Thread> myThreads = new ArrayList<Thread>();
    boolean numberFound = false;
    
    public void addThread(Finder t){
        Thread tempThread = new Thread(t);
        System.out.println("Adding Thread "+tempThread.getName());
        tempThread.start();
        myThreads.add(tempThread);
    }

    synchronized public void FoundNumber(){
        numberFound = true;
        System.out.println("Found Number");
        for(Thread temp:myThreads){
            System.out.println("Stopping Thread "+temp.getName());
            temp.interrupt();
        }
    }

    public void run() {
        System.out.println("Starting Monitor");
        while(!numberFound){
        }
    }
}
