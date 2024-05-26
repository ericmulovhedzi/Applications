/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package systemstray;

import java.awt.Image;
import java.awt.MenuItem;
import java.awt.PopupMenu;
import java.awt.SystemTray;
import java.awt.Toolkit;
import java.awt.TrayIcon;
import java.awt.Desktop;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.GridBagLayout;
import java.awt.GridLayout;
import java.awt.Dimension;
import java.awt.GridBagConstraints;
import java.awt.Color;
import java.awt.Font;
import java.awt.Insets;

import javax.swing.BorderFactory;
import javax.swing.border.Border;

import javax.swing.JTabbedPane;
import javax.swing.JComponent;
import javax.swing.JTabbedPane;
import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.JLabel;
import javax.swing.JButton;
import javax.swing.JTextField;
import javax.swing.JScrollPane;
import javax.swing.JTextPane;

import java.util.prefs.Preferences;

import java.net.URL;
import java.net.InetAddress;
import java.net.URLEncoder;

import javax.xml.parsers.DocumentBuilderFactory;
import javax.xml.parsers.DocumentBuilder;

import org.w3c.dom.NodeList;
import org.w3c.dom.Node;
import org.w3c.dom.Element;

import java.io.File;
import java.io.IOException;

/**
 *
 * @author emulovhedzi
 */
public class SystemsTray
{
    private static Preferences prefs;
    private static MenuItem mnItem[];
    private static JFrame frame;
    private static JTextField txt_XML_Path, txt_logo;
    private static String link;
    
    private static String termsOfUse = "<html><br />"
            + "<b>1. Terms of Use</b><br /><br />"
            + "You and or your Organisation are responsible for your use of the Services"
            
            + "<br /><br /><b>2. Privacy</b><br /><br />"
            + "Any information that you provide to <b><i>OVH SystemTray</i></b> is subject to our Privacy Policy (http://ovhfoundation.org/?p=privacy#ovh-system-tray), which governs our collection and use of your information."
            
            + "<br /><br /><b>3. Your License To Use the Software</b><br /><br />"
            + "<b><i>OVH SystemTray</i></b> gives you a personal, worldwide, royalty-free, non-assignable and non-exclusive license to use the software that is provided to you by <b>OVH Foundation Research Institute</b> as part of the Services. This license is for the sole purpose of enabling you to use and enjoy the benefit of the Services as provided by <b><i>OVH SystemTray</i></b>, in the manner permitted by these Terms."
            
            + "<br /><br /><b>4. Copyright</b><br /><br />"
            + "This product is FREE to use by any persons, anywhere in the world but remains a product of <b>OVH Foundation Research Institute</b>. All designs, Code and Implementations are 100% owned and shall be governed by <b>OVH Foundation Research Institute</b> and its members there-of."
            + "<br /><br /></html>";
    
    private static String privacyStament = "<html><br />"
            + "<b>Information Collection and Use:</b><br /><br />"
            + "We collect and use your information below to provide our services better and to measure and improve them over time."
            
            + "<br /><br /><b>Log Data</b><br /><br />"
            + "When you use our Services, we may receive information <b>Log Data</b> such as your device information (including device and application IDs), IP address, operating system and location."
            + "We receive Log Data when you interact with our Software or Services, for example, when you run the executable and when you click on links."
            + "<b>NB:</b> No user content information except the information mentioned above, the trend of use and user behavior of this Software shall be Logged and Sent to <b><i>OVH SystemTray</i></b>."
            + "<b><i>OVH SystemTray</i></b> uses Log Data to provide, understand, and improve our Services."
            
            + "<br /><br /><b>Changes to this Policy</b><br /><br />"
            + "We may revise this Privacy Policy from time to time. The most current version of the policy will govern our use of your information and will always be at http://ovhfoundation.org/?p=privacy#ovh-system-tray."
            + "If we make a change to this policy that, in our sole discretion, is material, we will notify you via the Software Updates Window."
            + "By continuing to access or use the Software after those changes become effective, you agree to be bound by the revised Privacy Policy."
            + "<br /><br /></html>";
    
    private static void launchAdress(String url) throws Exception
    {
        try
        {
            java.net.URI uri = new java.net.URI(url);

            java.awt.Desktop desktop = java.awt.Desktop.getDesktop();
            desktop.browse(uri);
        }
        catch(Exception e){System.err.println(e.getMessage());}
    }
    
    public static void addItem1(JPanel p, JComponent c,int x, int y, int width, int height, int align)
    {
        GridBagConstraints gc = new GridBagConstraints();
        gc.gridx = x;gc.gridy = y;gc.gridwidth = width;gc.gridheight = height;gc.weightx = 10.0;gc.weighty = 10.0;gc.insets = new Insets(2, 2, 2, 2);gc.anchor = align;gc.fill = GridBagConstraints.NONE;p.add(c, gc);
    }

    public static void addItem(JPanel p, JComponent c,int x, int y, int width, int height, int align)
    {
        GridBagConstraints gc = new GridBagConstraints();
        gc.gridx = x;gc.gridy = y;gc.gridwidth = width;gc.gridheight = height;gc.weightx = 100.0;gc.weighty = 100.0;gc.insets = new Insets(5, 5, 5, 5);gc.anchor = align;gc.fill = GridBagConstraints.NONE;p.add(c, gc);
    }

    
    public static void main(String[] args) throws Exception , IOException 
    {
        if(!SystemTray.isSupported()){System.out.println("SystemTray is not supported"); return;}
        
        SystemTray tray = SystemTray.getSystemTray();
        Toolkit toolkit = Toolkit.getDefaultToolkit();
        Image image = toolkit.getImage("pack/start-logo.png");

        PopupMenu menu = new PopupMenu();
        
        prefs = Preferences.userNodeForPackage(systemstray.SystemsTray.class);
        
        try // Build menu items
        {
            String str_xml_path;
            
            boolean existsPath = prefs.get("xml_path", null) != null;
            
            if(!existsPath) // if preference variable does not exist, please create one with a default path
            {
                prefs.put("xml_path","pack/menu.xml"); 
            }
            
            str_xml_path = prefs.get("xml_path","");
            File xmlFile = new File(str_xml_path);
            
            if(xmlFile.exists()) // check if Path or File Exists
            {
                if(!xmlFile.isDirectory())
                {
                    DocumentBuilderFactory dbFactory = DocumentBuilderFactory.newInstance();
                    DocumentBuilder dBuilder = dbFactory.newDocumentBuilder();
                    org.w3c.dom.Document doc = dBuilder.parse(xmlFile);
                    doc.getDocumentElement().normalize();

                    NodeList nList = doc.getElementsByTagName("item");

                    for(int i = 0;i < nList.getLength();i++)
                    {
                        Node nNode = nList.item(i);	    
                        if(nNode.getNodeType() == Node.ELEMENT_NODE)
                        {
                            Element eElement = (Element) nNode;

                            String label = getTagValue("label",eElement);
                            
                            if(label.equals("---"))menu.insertSeparator(i);
                            else
                            {
                                MenuItem nItem;
                                
                                boolean substrOVHSTExists = (label.toLowerCase().indexOf("ovhsl{title}.") >= 0);
                                boolean substrOVHSTminExists = (label.toLowerCase().indexOf("${title}.") >= 0);

                                if(substrOVHSTExists)
                                {
                                    nItem = new MenuItem(label.replace("ovhsl{title}.",""));
                                }
                                else if(substrOVHSTminExists)
                                {
                                    nItem = new MenuItem(label.replace("${title}.",""));
                                }else
                                {
                                    link =  getTagValue("link",eElement);
                                    
                                    if(link.isEmpty())
                                    {
                                        nItem = new MenuItem("   ! "+label);
                                    }
                                    else
                                    {
                                        nItem = new MenuItem("   "+label);
                                        nItem.addActionListener(new ActionListener(){public void actionPerformed(ActionEvent e) 
                                        {
                                            boolean substrHTTPExists = (link.toLowerCase().indexOf("http://") >= 0);
                                            if(!substrHTTPExists) link = "http://"+link;

                                            try{launchAdress(link);}catch(Exception e1){e1.printStackTrace();}
                                        }});
                                    }
                                }
                                menu.add(nItem);
                            }
                        }
                    }
                }
                else
                {
                    //System.out.println("NO");
                    //return;
                }
            }
            else // --- else get these from default xml file path
            {
                //System.out.println("NO");
                str_xml_path = prefs.get("xml_path","pack/menu.xml");
            }
        }
        catch(Exception e){e.printStackTrace();}
        
        menu.insertSeparator(95);
        
        MenuItem amSettings = new MenuItem("Preferences...");
        amSettings.addActionListener(new ActionListener(){public void actionPerformed(ActionEvent e) 
        {
            // --- Create Settings GUI
            
            JTabbedPane tab = new JTabbedPane();
            frame = new JFrame("OVH SystemTray Preference");
            
                JPanel xmlPathPanel = new JPanel();
                JPanel termsPanel = new JPanel();
                JPanel privacyPanel = new JPanel();
                JPanel updatesPanel = new JPanel();
                
                xmlPathPanel.setLayout(new GridLayout(3,3));
                xmlPathPanel.setBorder(BorderFactory.createCompoundBorder(BorderFactory.createEmptyBorder(75, 10, 75, 10), BorderFactory.createTitledBorder("Path Settings:")));
                
                termsPanel.setLayout(new GridLayout(1,1));
                termsPanel.setBorder(BorderFactory.createTitledBorder("Terms of Service:"));
                
                privacyPanel.setLayout(new GridLayout(1,1));
                privacyPanel.setBorder(BorderFactory.createTitledBorder("Privacy Policy:"));
                
                updatesPanel.setLayout(new GridBagLayout());
                updatesPanel.setBorder(BorderFactory.createTitledBorder("Updates:"));
                
                    // --- Paths Tab
                    
                    String str_xml_path = prefs.get("xml_path",""); 
                    String str_logo_path = prefs.get("logo_path",""); 
                                
                    JLabel lb_XML_Path = new JLabel("XML Path:");
                    JLabel lb_logo = new JLabel("Logo Path:");
                    
                    txt_XML_Path = new JTextField(20);txt_logo = new JTextField(20);
                    
                    txt_XML_Path.setText(str_xml_path);txt_logo.setText(str_logo_path);
                    
                    JButton btn_cancel = new JButton("Cancel");
                    JButton btn_save = new JButton("Save");
                    
                    addItem(xmlPathPanel, lb_XML_Path , 1, 1, 1, 1, GridBagConstraints.NORTHWEST);
                    addItem(xmlPathPanel, txt_XML_Path, 1, 1, 1, 1, GridBagConstraints.NORTHWEST);
                    
                    addItem(xmlPathPanel, lb_logo, 1, 1, 1, 1, GridBagConstraints.NORTHWEST);
                    addItem(xmlPathPanel, txt_logo, 1, 1, 1, 1, GridBagConstraints.NORTHWEST);
                    
                    addItem(xmlPathPanel, btn_cancel, 1, 1, 1, 1, GridBagConstraints.NORTHWEST);
                    addItem(xmlPathPanel, btn_save, 1, 1, 1, 1, GridBagConstraints.NORTHWEST);

                        btn_save.addActionListener(new ActionListener(){public void actionPerformed(ActionEvent e)
                        {
                            try
                            {
                                prefs.put("xml_path",txt_XML_Path.getText());
                                prefs.put("logo_path",txt_logo.getText());
                                
                                //String str_xml_path = prefs.get("xml_path",""); 
                                //String str_logo_path = prefs.get("logo_path",""); 
                                
                            } catch (Exception e1){System.err.println(e1.getMessage());}
                        }});
                        
                        btn_cancel.addActionListener(new ActionListener(){public void actionPerformed(ActionEvent e)
                        {
                            try
                            {
                                frame.setVisible(false);
                            } catch (Exception e1){System.err.println(e1.getMessage());}
                        }});
                        
                    // --- Terms Tab
                            
                    JTextPane termsTextPane = new JTextPane();
                    termsTextPane.setContentType("text/html");
                    termsTextPane.setFont(new Font("Serif", Font.PLAIN, 12));
                    termsTextPane.setText(termsOfUse);
                    
                    JScrollPane termsScrollPane = new JScrollPane(termsTextPane); 
                    termsScrollPane.setVerticalScrollBarPolicy(JScrollPane.VERTICAL_SCROLLBAR_ALWAYS);
                    
                    termsScrollPane.setPreferredSize(new Dimension(450, 250));
                    
            addItem(termsPanel,termsScrollPane , 1, 1, 1, 1, GridBagConstraints.NORTHWEST);
                           
                    // --- Privacy Tab
                            
                    JTextPane privacyTextPane = new JTextPane();
                    privacyTextPane.setContentType("text/html");
                    privacyTextPane.setFont(new Font("Serif", Font.PLAIN, 12));
                    privacyTextPane.setText(privacyStament);
                    
                    JScrollPane privacyScrollPane = new JScrollPane(privacyTextPane); 
                    privacyScrollPane.setVerticalScrollBarPolicy(JScrollPane.VERTICAL_SCROLLBAR_ALWAYS);
                    
                    privacyScrollPane.setPreferredSize(new Dimension(450, 250));
                    
            addItem(privacyPanel,privacyScrollPane , 1, 1, 1, 1, GridBagConstraints.NORTHWEST);
                        
                    // --- Updates Tab
                            
                    JTextPane updatesTextPane = new JTextPane();
                    updatesTextPane.setContentType("text/html");
                    updatesTextPane.setFont(new Font("Serif", Font.PLAIN, 12));
                    
                    //java.net.URL updatesURL = systemstray.SystemsTray.class.getResource("http://ovhfoundation.org/?p=home");
                    
                    try // --- LAUNCH URL
                    {
                        /*java.net.URL oracle = new URL("http://ovhfoundation.org/?p=home");
                     
                        java.net.URLConnection yc = oracle.openConnection();
                        java.io.BufferedReader in = new java.io.BufferedReader(new java.io.InputStreamReader(yc.getInputStream()));
                        String inputLine;while((inputLine = in.readLine()) != null)updatesTextPane.setText(inputLine);
                        //inputLine +=inputLine;
                        //updatesTextPane.setText(inputLine);
                        System.err.println(inputLine);
                        in.close();
                        */
                        updatesTextPane.setText("<html><b style='color:red'>No updates available yet.</b></html>");
                    } 
                    catch (Exception ex1){updatesTextPane.setText("<html><b style='color:red'>Couldn't retrive updates.</b></html>");}
        
                    JScrollPane updatesScrollPane = new JScrollPane(updatesTextPane); 
                    updatesScrollPane.setVerticalScrollBarPolicy(JScrollPane.VERTICAL_SCROLLBAR_ALWAYS);
                    
                    updatesScrollPane.setPreferredSize(new Dimension(450, 250));
                    
            addItem(updatesPanel,updatesScrollPane , 1, 1, 1, 1, GridBagConstraints.NORTHWEST);
                        
                    
        
            tab.addTab("XML Path", xmlPathPanel);
            tab.addTab("Terms", termsPanel);
            tab.addTab("Privacy", privacyPanel);
            tab.addTab("Updates", updatesPanel);

            frame.add("North", tab);
            //frame.add(panelBottm,BorderLayout.CENTER);
            //frame.add(panelBottmBottom,BorderLayout.CENTER);
            frame.setSize(500, 350);
            frame.setResizable(false);
            frame.toFront();
            frame.repaint();
            //frame.setUndecorated(true);
            //frame.getRootPane().setWindowDecorationStyle(JRootPane.PLAIN_DIALOG);
            frame.setVisible(true);

        
        }});
        menu.add(amSettings);
        
        MenuItem amAbout = new MenuItem("About OVH SystemTray");
        amAbout.addActionListener(new ActionListener(){public void actionPerformed(ActionEvent e) 
        {
            try
            {
                Desktop.getDesktop().browse(new URL("http://ovhfoundation.org/?p=ovh-system-tray").toURI());
            }
            catch(Exception e1){}

        }});
        menu.add(amAbout);
        
        menu.insertSeparator(100);
        MenuItem closeItem = new MenuItem("Remove Icon");
        closeItem.addActionListener(new ActionListener(){public void actionPerformed(ActionEvent e){System.exit(0);}});
        menu.add(closeItem);
        
        TrayIcon icon = new TrayIcon(image, "", menu);
        icon.setImageAutoSize(true);

        tray.add(icon);
        
        String computername = URLEncoder.encode(InetAddress.getLocalHost().getHostName());
        String CanonicalHostName = URLEncoder.encode(InetAddress.getLocalHost().getHostName());
        String HostAddress = URLEncoder.encode(InetAddress.getLocalHost().getHostAddress()); 
        
        try
        {
            java.net.URL oracle = new URL("http://ovhfoundation.org/logs/ovhsystemtray/ovhsystemtray.php?_c="+computername+"&_ip="+CanonicalHostName+"&_host="+HostAddress);
            java.net.URLConnection yc = oracle.openConnection();
            yc.getInputStream();
        }
        catch(Exception e1){}
    }
    
    private static String getTagValue(String sTag, Element eElement)
    {
        NodeList nlList= eElement.getElementsByTagName(sTag).item(0).getChildNodes();
        Node nValue = (Node) nlList.item(0); 
        
        String str = "";
        if(nValue != null)str = nValue.getNodeValue();
        
        return str;    
    }
}