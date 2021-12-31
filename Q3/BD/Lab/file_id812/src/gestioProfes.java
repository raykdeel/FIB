import java.sql.*;
import java.util.Properties;

public class gestioProfes
   {
   public static void main (String args[])
     {
	try
	   {
	   // carregar el driver al controlador
	   Class.forName ("org.postgresql.Driver");
           System.out.println ();
	   System.out.println ("Driver de PostgreSQL carregat correctament.");
           System.out.println ();


	   // connectar a la base de dades
	   // cal modificar el username, password i el nom de la base de dades
	   // en el servidor postgresfib, SEMPRE el SSL ha de ser true 
       Properties props = new Properties();
       props.setProperty("user","ricard.guixaro");
       props.setProperty("password","DB090101");
       props.setProperty("ssl","true");
       props.setProperty("sslfactory", "org.postgresql.ssl.NonValidatingFactory"); 
       Connection c = DriverManager.getConnection("jdbc:postgresql://postgresfib.fib.upc.es:6433/DBricard.guixaro", props);
       c.setAutoCommit(false);
       System.out.println("Connexio realitzada correctament.");
       System.out.println();


	   // canvi de l'esquema per defecte a un altre esquema
       Statement s = c.createStatement();
		 s.executeUpdate("set search_path to public;");
		 s.close();					
	   System.out.println ("Canvi d'esquema realitzat correctament.");
         System.out.println ();

           
	   // IMPLEMENTAR CONSULTA
       String[] telfsProf = {"3111", "3222", "3333", "4444"};
       
       Statement p = c.createStatement();
       ResultSet rs = p.executeQuery("select p.dni, p.nomProf "+"from professors p "+"where p.telefon IN '"+telfsProf+"';");
       String dnii = null;
       String nomm = null;
       while(rs.next()) {
    	   dnii = rs.getString("dni");
    	   nomm = rs.getString("nomProf");
    	   System.out.println("Professor "+nomm+" amb dni "+dnii);
       }
       p.close();
      
		   
	   // IMPLEMENTAR CANVI BD       

       
	   // Commit i desconnexio de la base de dades
	   c.commit();
	   c.close();
	   System.out.println ("Commit i desconnexio realitzats correctament.");
	   }
	
	catch (ClassNotFoundException ce)
	   {
	   System.out.println ("Error al carregar el driver");
	   }	
	catch (SQLException se)
	   {
           System.out.println ("Excepcio: ");System.out.println ();
	   System.out.println ("El getSQLState es: " + se.getSQLState());
           System.out.println ();
	   System.out.println ("El getMessage es: " + se.getMessage());	   
	   }
  }
}