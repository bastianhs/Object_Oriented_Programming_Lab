class SebuahHandler {
    @HttpVar(type = HttpVar.Type.Query, name = "q")
    private String q;

    private String token;

    // atribut lainnya...

    @HttpVar(type = HttpVar.Type.Header, name = "Authorization")
    public void initToken(String auth) {
        // implementasi set token dari header auth
    }

    // method-method handler...
}