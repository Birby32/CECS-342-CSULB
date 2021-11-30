package Lab6;

import java.util.Random;

// Main Class
public class Multithread {
    public static void main(String[] args){
        int RANDOM_VALUE = new Random().nextInt(1000);
        System.out.println("Random Value :"+RANDOM_VALUE);
        System.out.println("------- PART 1 -------");
        Threading thread1 = new Threading(0,RANDOM_VALUE);
        thread1.start();
        Threading thread2 = new Threading(250,RANDOM_VALUE);
        thread2.start();
        Threading thread3 = new Threading(500,RANDOM_VALUE);
        thread3.start();
        Threading thread4 = new Threading(750,RANDOM_VALUE);
        thread4.start();
        try {
            Thread.sleep(1000);
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
        //Part 2
        System.out.println("------- PART 2 -------");
        Runablethread rthread1 = new Runablethread(0,RANDOM_VALUE);
        Thread myThread1 = new Thread(rthread1);
        myThread1.start();

        Runablethread rthread2 = new Runablethread(250,RANDOM_VALUE);
        Thread myThread2 = new Thread(rthread2);
        myThread2.start();

        Runablethread rthread3 = new Runablethread(500,RANDOM_VALUE);
        Thread myThread3 = new Thread(rthread3);
        myThread3.start();

        Runablethread rthread4 = new Runablethread(750,RANDOM_VALUE);
        Thread myThread4 = new Thread(rthread4);
        myThread4.start();

        try {
            Thread.sleep(1000);
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
        // Part 3 
        System.out.println("------- PART 3 -------");
        monitorThread mThread = new monitorThread();
        Finder fThread1 = new Finder(0,RANDOM_VALUE,mThread);
        Finder fThread2 = new Finder(250,RANDOM_VALUE,mThread);
        Finder fThread3 = new Finder(500,RANDOM_VALUE,mThread);
        Finder fThread4 = new Finder(750,RANDOM_VALUE,mThread);
        mThread.start();

        mThread.addThread(fThread1);
        mThread.addThread(fThread2);
        mThread.addThread(fThread3);
        mThread.addThread(fThread4);
    }
}