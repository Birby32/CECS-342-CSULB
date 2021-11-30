package Lab6;

class Threading extends Thread {
    int start;
    int key;
    Threading(int start,int key){
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