package Lab6;
// Java code for thread creation by extending
// the Thread class
class MultithreadingDemo extends Thread {
    int start;
    int key;
    MultithreadingDemo(int start,int key){
        this.start = start;
        this.key = key;
    }

    public void run(){
        try {
            String name = this.getName();
            for(int i = start; i < start+ 250;i++){
                if(i == key)
                    System.out.println("Found value "+i+" in thread "+name);
            }
        }
        catch (Exception e) {
            // Throwing an exception
            System.out.println("Exception is caught");
        }
    }
}