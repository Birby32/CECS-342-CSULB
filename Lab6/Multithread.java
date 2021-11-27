package Lab6;

import java.util.Random;

// Main Class
public class Multithread {
    public static void main(String[] args){
        int RANDOM_VALUE = new Random().nextInt(1000);
        System.out.println("Random Value :"+RANDOM_VALUE);
        MultithreadingDemo thread1 = new MultithreadingDemo(0,RANDOM_VALUE);
        thread1.start();
        MultithreadingDemo thread2 = new MultithreadingDemo(250,RANDOM_VALUE);
        thread2.start();
        MultithreadingDemo thread3 = new MultithreadingDemo(500,RANDOM_VALUE);
        thread3.start();
        MultithreadingDemo thread4 = new MultithreadingDemo(750,RANDOM_VALUE);
        thread4.start();
        
        //Runnable Thread
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
    }
}