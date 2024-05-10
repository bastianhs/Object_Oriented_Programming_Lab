import java.lang.reflect.Field;
import java.lang.reflect.Method;
import java.util.ArrayList;
import java.util.List;

public class Reflection{
    //TIDAK BOLEH MENGUBAH NAMA METHOD YANG SUDAH ADA DAN PARAMS SERTA INPUT TYPENYA
    //BOLEH MENAMBAHKAN PRIVATE / PROTECTED METHOD SESUAI DENGAN KEBUTUHAN
    //DI LUAR SANA ADA KELAS YANG NAMANYA Ghost DAN Secret.

    public ArrayList<String> ghostMethods() throws ClassNotFoundException {
        Class<?> ghostClass = Class.forName("Ghost");
        Method[] ghostMethods = ghostClass.getDeclaredMethods();
        ArrayList<String> ghostMethodsNames = new ArrayList<>();
        for (Method ghostMethod : ghostMethods) {
            ghostMethodsNames.add(ghostMethod.getName());
        }
        return ghostMethodsNames;
    }

    public Integer sumGhost() throws Exception {
        Class<?> ghostClass = Class.forName("Ghost");
        Method[] ghostMethods = ghostClass.getDeclaredMethods();
        Integer sum = 0;
        for (Method ghostMethod : ghostMethods) {
            ghostMethod.setAccessible(true);
            if (ghostMethod.getReturnType().equals(Integer.class)) {
                Integer result = (Integer) ghostMethod.invoke(ghostClass.getDeclaredConstructor().newInstance());
                sum += result;
            }
        }
        return sum;
    }

    public String letterGhost() throws Exception {
        Class<?> ghostClass = Class.forName("Ghost");
        Method[] ghostMethods = ghostClass.getDeclaredMethods();
        StringBuilder concatenated = new StringBuilder();
        for (Method ghostMethod : ghostMethods) {
            ghostMethod.setAccessible(true);
            if (ghostMethod.getReturnType().equals(String.class)) {
                String result = (String) ghostMethod.invoke(ghostClass.getDeclaredConstructor().newInstance());
                concatenated.append(result);
            }
        }
        return concatenated.toString();
    }

    public String findSecretId(List<Secret> sl, String email) throws Exception {
        for (Secret secret : sl) {
            if (secret.isThis(email)) {
                Class<?> secretClass = secret.getClass();
                Field uniqueId = secretClass.getDeclaredField("uniqueId");
                uniqueId.setAccessible(true);
                return (String) uniqueId.get(secret);
            }
        }
        return "NaN";
    }
}
