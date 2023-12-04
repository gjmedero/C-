import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.io.*;
import java.util.*;

class Synchronizer {
	private boolean methodOneCall = false;

	public synchronized void firstMethod() {
		while(methodOneCall) {
			try {
				wait();
			} catch (InterruptedException e) {
				e.printStackTrace();
			}
		}

		// Method One logic
		System.out.println("Counting up in Thread 1");

		for (int i = 0; i <= 20; i++) {
			System.out.println(i);
		}

		System.out.println();

		methodOneCall = true;
		notify();
	}

	public synchronized void secondMethod() {
		while(!methodOneCall) {
			try {
				wait();
			} catch (InterruptedException e) {
				e.printStackTrace();
			}
		}

		//Method two logic
		System.out.println("Counting down in Thread 2");

		for (int i = 20; i >= 0; i--) {
			System.out.println(i);
		}

		System.out.println();

		notify();
	}
}

class ThreadOne extends Thread {
	private Synchronizer mySynchronizer;

	public ThreadOne(Synchronizer mySynchronizer) {
		this.mySynchronizer = mySynchronizer;
	}

	public void run() {
		mySynchronizer.firstMethod();
	}
}

class ThreadTwo extends Thread {
	private Synchronizer mySynchronizer;

	public ThreadTwo(Synchronizer mySynchronizer) {
		this.mySynchronizer = mySynchronizer;
	}

	public void run() {
		mySynchronizer.secondMethod();
	}
}


public class SyncCount {
	public static void main(String[] args) {
		Synchronizer mySynchronizer = new Synchronizer();

		ThreadOne firstThread = new ThreadOne(mySynchronizer);
		ThreadTwo secondThread = new ThreadTwo(mySynchronizer);

		firstThread.start();
		secondThread.start();

		try {
			firstThread.join();
			secondThread.join();
		} catch (InterruptedException e) {
			e.printStackTrace();
		}

		System.out.println("Program done");
	}
}