package io.github.scarger.chat.util;

import io.github.scarger.chat.LowLevelChat;

import java.io.*;

public class Translator {

    public native int encrypt(final String text);

    public native String translate(int address);

    public native void dispose();

    public Translator() {
        //Windows implementation, which is what I use
        File libFile = new File(LowLevelChat.context.getDataFolder(),"Translator.dll");
        LowLevelChat.context.getDataFolder().mkdirs();
        if(!libFile.exists()) {
            try {
                libFile.createNewFile();
                try(InputStream in = getClass().getResourceAsStream("/Translator.dll");
                    FileOutputStream out = new FileOutputStream(libFile)) {
                    byte buffer[] = new byte[1024];
                    int length;
                    while((length = in.read(buffer)) > 0) {
                        out.write(buffer,0,length);
                    }
                } catch (Exception e) {
                    e.printStackTrace();
                }
            } catch (IOException e) {
                e.printStackTrace();
            }
        }
        System.load(libFile.getAbsolutePath());
    }

}
