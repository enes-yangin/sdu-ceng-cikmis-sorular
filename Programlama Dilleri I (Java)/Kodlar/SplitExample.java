public class SplitExample {
    public static void main(String[] args) {
        String text = "Hello   world! This is a test.";
        String[] words = text.split("\\s+"); //s'nin yanında + kullanırsak fazladan koyulan boşlkları saymaz 

        System.out.println("Kelime sayısı: " + words.length);
        for(String word : words){
            System.out.println(word);
        }
    }
}
