import java.util.ArrayList;
import java.util.List;

public class DataParser {
    private static List<String> validCountryCodes = new ArrayList<String>(); // Note: Country Code mungkin saja ditambah. Format country code selalu +XX

    public DataParser() {
        validCountryCodes.add("+62");
    }

    public void addCountryCode(String code) {
        validCountryCodes.add(code);
    }

    // Return true apabila phone valid. Panjang phone number yang valid minimal 8 dan maksimal 10 angka setelah country code.
    // Apabila country code tidak ditemukan di list of validCountryCodes, throw InvalidCountryException
    // Apabila panjang nomor tidak valid, throw InvalidPhoneLengthException
    // Tips: Gunakan StringBuilder
    public boolean parsePhone(String phone) throws InvalidCountryException, InvalidPhoneLengthException {
        StringBuilder phoneSB = new StringBuilder(phone);
        boolean countryCodeValid = false;
        for (int i = 0; i < validCountryCodes.size(); ++i) {
            if (phoneSB.indexOf(validCountryCodes.get(i)) == 0) {
                countryCodeValid = true;
                phoneSB.delete(0, validCountryCodes.get(i).length());
                break;
            }
        }

        if (!countryCodeValid) {
            throw new InvalidCountryException();
        }

        if (phoneSB.length() < 8 || phoneSB.length() > 10) {
            throw new InvalidPhoneLengthException();
        }

        return true;
    }

    // Return true apabila email valid. Email yang valid adalah email dengan format *@*.*
    // A@gmail.co.com.id adalah email yang valid
    // A.B.C@mail.co adalah email yang valid
    // @gmail.com tidak valid dan akan throw InvalidEmailUserException
    // A@gmail tidak valid dan akan throw InvalidEmailDomainException
    // Algoritma akan mengecek username terlebih dahulu sebelum mengecek domain dari email
    // Dipastikan ada satu @
    public boolean parseEmail(String email) throws InvalidEmailUserException, InvalidEmailDomainException {
        StringBuilder emailSB = new StringBuilder(email);
        int indexAtSymbol = emailSB.indexOf("@");
        String username = emailSB.substring(0, indexAtSymbol);
        
        if (username.length() < 1) {
            throw new InvalidEmailUserException();
        }

        String domain = emailSB.substring(indexAtSymbol + 1);
        // int indexDotSymbol = domain.indexOf(".");
        // String beforeDot = domain.substring(0, indexDotSymbol);
        // String afterDot = domain.substring(indexDotSymbol + 1);
        // if (beforeDot.length() < 1 || afterDot.length() < 1) {
        //     throw new InvalidEmailDomainException();
        // }
        //
        // return true;

        for (int i = 0; i < domain.length(); ++i) {
            if (domain.charAt(i) == '.') {
                String beforeDot = domain.substring(0, i);
                String afterDot = domain.substring(i + 1);
                if (!beforeDot.isEmpty() && !afterDot.isEmpty()) {
                    return true;
                }
            }
        }

        throw new InvalidEmailDomainException();
    }
}
