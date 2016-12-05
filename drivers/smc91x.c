<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml" xml:lang="en" lang="en">
<head>
<title>Linux/drivers/net/ethernet/smsc/smc91x.c - Linux Cross Reference - Free Electrons</title>
<link rel="stylesheet" href="/style.css" type="text/css" media="screen" />
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8" />
<meta description="Linux Cross-Reference (LXR) service by Free Electrons. The easiest way to study Linux kernel sources. Available for all recent releases." />
<base href="http://lxr.free-electrons.com/"/>
</head>

<body>

<div id="wrapper">
<div id="wrapper2">
<div id="header">

	<div id="logo">
		<h1>Linux Cross Reference</h1>
		<h2><a href="http://free-electrons.com">Free Electrons</a></h2>
		<h2>Embedded Linux Experts</h2>
		<p>
		 &nbsp;&bull;&nbsp;<b><i>source navigation</i></b> &nbsp;&bull;&nbsp;<a href="diff/drivers/net/ethernet/smsc/smc91x.c">diff markup</a> &nbsp;&bull;&nbsp;<a href="ident">identifier search</a> &nbsp;&bull;&nbsp;<a href="search">freetext search</a> &nbsp;&bull;&nbsp;
		</p>
	</div>
</div>

<div id="topbar">
  
  <p>Version: &nbsp;<a href="source/drivers/net/ethernet/smsc/smc91x.c?v=2.0.40">2.0.40</a>&nbsp;<a href="source/drivers/net/ethernet/smsc/smc91x.c?v=2.2.26">2.2.26</a>&nbsp;<a href="source/drivers/net/ethernet/smsc/smc91x.c?v=2.4.37">2.4.37</a>&nbsp;<a href="source/drivers/net/ethernet/smsc/smc91x.c?v=3.11">3.11</a>&nbsp;<a href="source/drivers/net/ethernet/smsc/smc91x.c?v=3.12">3.12</a>&nbsp;<a href="source/drivers/net/ethernet/smsc/smc91x.c?v=3.13">3.13</a>&nbsp;<a href="source/drivers/net/ethernet/smsc/smc91x.c?v=3.14">3.14</a>&nbsp;<a href="source/drivers/net/ethernet/smsc/smc91x.c?v=3.15">3.15</a>&nbsp;<a href="source/drivers/net/ethernet/smsc/smc91x.c?v=3.16">3.16</a>&nbsp;<a href="source/drivers/net/ethernet/smsc/smc91x.c?v=3.17">3.17</a>&nbsp;<a href="source/drivers/net/ethernet/smsc/smc91x.c?v=3.18">3.18</a>&nbsp;<a href="source/drivers/net/ethernet/smsc/smc91x.c?v=3.19">3.19</a>&nbsp;<a href="source/drivers/net/ethernet/smsc/smc91x.c?v=4.0">4.0</a>&nbsp;<a href="source/drivers/net/ethernet/smsc/smc91x.c?v=4.1">4.1</a>&nbsp;<a href="source/drivers/net/ethernet/smsc/smc91x.c?v=4.2">4.2</a>&nbsp;<a href="source/drivers/net/ethernet/smsc/smc91x.c?v=4.3">4.3</a>&nbsp;<a href="source/drivers/net/ethernet/smsc/smc91x.c?v=4.4">4.4</a>&nbsp;<a href="source/drivers/net/ethernet/smsc/smc91x.c?v=4.5">4.5</a>&nbsp;<a href="source/drivers/net/ethernet/smsc/smc91x.c?v=4.6">4.6</a>&nbsp;<a href="source/drivers/net/ethernet/smsc/smc91x.c?v=4.7">4.7</a>&nbsp;<b><i>4.8</i></b></p>
  
</div>

<h1><a href="source/">Linux</a>/<a href="source/drivers/">drivers</a>/<a href="source/drivers/net/">net</a>/<a href="source/drivers/net/ethernet/">ethernet</a>/<a href="source/drivers/net/ethernet/smsc/">smsc</a>/<a href="source/drivers/net/ethernet/smsc/smc91x.c">smc91x.c</a></h1>
<div id="lxrcode"><pre>  <a name="L1" href="source/drivers/net/ethernet/smsc/smc91x.c#L1">1</a> <b><i>/*</i></b>
  <a name="L2" href="source/drivers/net/ethernet/smsc/smc91x.c#L2">2</a> <b><i> * smc91x.c</i></b>
  <a name="L3" href="source/drivers/net/ethernet/smsc/smc91x.c#L3">3</a> <b><i> * This is a driver for SMSC's 91C9x/91C1xx single-chip Ethernet devices.</i></b>
  <a name="L4" href="source/drivers/net/ethernet/smsc/smc91x.c#L4">4</a> <b><i> *</i></b>
  <a name="L5" href="source/drivers/net/ethernet/smsc/smc91x.c#L5">5</a> <b><i> * Copyright (C) 1996 by Erik Stahlman</i></b>
  <a name="L6" href="source/drivers/net/ethernet/smsc/smc91x.c#L6">6</a> <b><i> * Copyright (C) 2001 Standard Microsystems Corporation</i></b>
  <a name="L7" href="source/drivers/net/ethernet/smsc/smc91x.c#L7">7</a> <b><i> *      Developed by Simple Network Magic Corporation</i></b>
  <a name="L8" href="source/drivers/net/ethernet/smsc/smc91x.c#L8">8</a> <b><i> * Copyright (C) 2003 Monta Vista Software, Inc.</i></b>
  <a name="L9" href="source/drivers/net/ethernet/smsc/smc91x.c#L9">9</a> <b><i> *      Unified SMC91x driver by Nicolas Pitre</i></b>
 <a name="L10" href="source/drivers/net/ethernet/smsc/smc91x.c#L10">10</a> <b><i> *</i></b>
 <a name="L11" href="source/drivers/net/ethernet/smsc/smc91x.c#L11">11</a> <b><i> * This program is free software; you can redistribute it and/or modify</i></b>
 <a name="L12" href="source/drivers/net/ethernet/smsc/smc91x.c#L12">12</a> <b><i> * it under the terms of the GNU General Public License as published by</i></b>
 <a name="L13" href="source/drivers/net/ethernet/smsc/smc91x.c#L13">13</a> <b><i> * the Free Software Foundation; either version 2 of the License, or</i></b>
 <a name="L14" href="source/drivers/net/ethernet/smsc/smc91x.c#L14">14</a> <b><i> * (at your option) any later version.</i></b>
 <a name="L15" href="source/drivers/net/ethernet/smsc/smc91x.c#L15">15</a> <b><i> *</i></b>
 <a name="L16" href="source/drivers/net/ethernet/smsc/smc91x.c#L16">16</a> <b><i> * This program is distributed in the hope that it will be useful,</i></b>
 <a name="L17" href="source/drivers/net/ethernet/smsc/smc91x.c#L17">17</a> <b><i> * but WITHOUT ANY WARRANTY; without even the implied warranty of</i></b>
 <a name="L18" href="source/drivers/net/ethernet/smsc/smc91x.c#L18">18</a> <b><i> * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the</i></b>
 <a name="L19" href="source/drivers/net/ethernet/smsc/smc91x.c#L19">19</a> <b><i> * GNU General Public License for more details.</i></b>
 <a name="L20" href="source/drivers/net/ethernet/smsc/smc91x.c#L20">20</a> <b><i> *</i></b>
 <a name="L21" href="source/drivers/net/ethernet/smsc/smc91x.c#L21">21</a> <b><i> * You should have received a copy of the GNU General Public License</i></b>
 <a name="L22" href="source/drivers/net/ethernet/smsc/smc91x.c#L22">22</a> <b><i> * along with this program; if not, see &lt;<a href="http://www.gnu.org/licenses/&gt;">http://www.gnu.org/licenses/&gt;</a>.</i></b>
 <a name="L23" href="source/drivers/net/ethernet/smsc/smc91x.c#L23">23</a> <b><i> *</i></b>
 <a name="L24" href="source/drivers/net/ethernet/smsc/smc91x.c#L24">24</a> <b><i> * Arguments:</i></b>
 <a name="L25" href="source/drivers/net/ethernet/smsc/smc91x.c#L25">25</a> <b><i> *      io      = for the base address</i></b>
 <a name="L26" href="source/drivers/net/ethernet/smsc/smc91x.c#L26">26</a> <b><i> *      irq     = for the IRQ</i></b>
 <a name="L27" href="source/drivers/net/ethernet/smsc/smc91x.c#L27">27</a> <b><i> *      nowait  = 0 for normal wait states, 1 eliminates additional wait states</i></b>
 <a name="L28" href="source/drivers/net/ethernet/smsc/smc91x.c#L28">28</a> <b><i> *</i></b>
 <a name="L29" href="source/drivers/net/ethernet/smsc/smc91x.c#L29">29</a> <b><i> * original author:</i></b>
 <a name="L30" href="source/drivers/net/ethernet/smsc/smc91x.c#L30">30</a> <b><i> *      Erik Stahlman &lt;erik@vt.edu&gt;</i></b>
 <a name="L31" href="source/drivers/net/ethernet/smsc/smc91x.c#L31">31</a> <b><i> *</i></b>
 <a name="L32" href="source/drivers/net/ethernet/smsc/smc91x.c#L32">32</a> <b><i> * hardware multicast code:</i></b>
 <a name="L33" href="source/drivers/net/ethernet/smsc/smc91x.c#L33">33</a> <b><i> *    Peter Cammaert &lt;pc@denkart.be&gt;</i></b>
 <a name="L34" href="source/drivers/net/ethernet/smsc/smc91x.c#L34">34</a> <b><i> *</i></b>
 <a name="L35" href="source/drivers/net/ethernet/smsc/smc91x.c#L35">35</a> <b><i> * contributors:</i></b>
 <a name="L36" href="source/drivers/net/ethernet/smsc/smc91x.c#L36">36</a> <b><i> *      Daris A Nevil &lt;dnevil@snmc.com&gt;</i></b>
 <a name="L37" href="source/drivers/net/ethernet/smsc/smc91x.c#L37">37</a> <b><i> *      Nicolas Pitre &lt;nico@fluxnic.net&gt;</i></b>
 <a name="L38" href="source/drivers/net/ethernet/smsc/smc91x.c#L38">38</a> <b><i> *      Russell King &lt;rmk@arm.linux.org.uk&gt;</i></b>
 <a name="L39" href="source/drivers/net/ethernet/smsc/smc91x.c#L39">39</a> <b><i> *</i></b>
 <a name="L40" href="source/drivers/net/ethernet/smsc/smc91x.c#L40">40</a> <b><i> * History:</i></b>
 <a name="L41" href="source/drivers/net/ethernet/smsc/smc91x.c#L41">41</a> <b><i> *   08/20/00  Arnaldo Melo       fix kfree(skb) in smc_hardware_send_packet</i></b>
 <a name="L42" href="source/drivers/net/ethernet/smsc/smc91x.c#L42">42</a> <b><i> *   12/15/00  Christian Jullien  fix "Warning: kfree_skb on hard IRQ"</i></b>
 <a name="L43" href="source/drivers/net/ethernet/smsc/smc91x.c#L43">43</a> <b><i> *   03/16/01  Daris A Nevil      modified smc9194.c for use with LAN91C111</i></b>
 <a name="L44" href="source/drivers/net/ethernet/smsc/smc91x.c#L44">44</a> <b><i> *   08/22/01  Scott Anderson     merge changes from smc9194 to smc91111</i></b>
 <a name="L45" href="source/drivers/net/ethernet/smsc/smc91x.c#L45">45</a> <b><i> *   08/21/01  Pramod B Bhardwaj  added support for RevB of LAN91C111</i></b>
 <a name="L46" href="source/drivers/net/ethernet/smsc/smc91x.c#L46">46</a> <b><i> *   12/20/01  Jeff Sutherland    initial port to Xscale PXA with DMA support</i></b>
 <a name="L47" href="source/drivers/net/ethernet/smsc/smc91x.c#L47">47</a> <b><i> *   04/07/03  Nicolas Pitre      unified SMC91x driver, killed irq races,</i></b>
 <a name="L48" href="source/drivers/net/ethernet/smsc/smc91x.c#L48">48</a> <b><i> *                                more bus abstraction, big cleanup, etc.</i></b>
 <a name="L49" href="source/drivers/net/ethernet/smsc/smc91x.c#L49">49</a> <b><i> *   29/09/03  Russell King       - add driver model support</i></b>
 <a name="L50" href="source/drivers/net/ethernet/smsc/smc91x.c#L50">50</a> <b><i> *                                - ethtool support</i></b>
 <a name="L51" href="source/drivers/net/ethernet/smsc/smc91x.c#L51">51</a> <b><i> *                                - convert to use generic MII interface</i></b>
 <a name="L52" href="source/drivers/net/ethernet/smsc/smc91x.c#L52">52</a> <b><i> *                                - add link up/down notification</i></b>
 <a name="L53" href="source/drivers/net/ethernet/smsc/smc91x.c#L53">53</a> <b><i> *                                - don't try to handle full negotiation in</i></b>
 <a name="L54" href="source/drivers/net/ethernet/smsc/smc91x.c#L54">54</a> <b><i> *                                  smc_phy_configure</i></b>
 <a name="L55" href="source/drivers/net/ethernet/smsc/smc91x.c#L55">55</a> <b><i> *                                - clean up (and fix stack overrun) in PHY</i></b>
 <a name="L56" href="source/drivers/net/ethernet/smsc/smc91x.c#L56">56</a> <b><i> *                                  MII read/write functions</i></b>
 <a name="L57" href="source/drivers/net/ethernet/smsc/smc91x.c#L57">57</a> <b><i> *   22/09/04  Nicolas Pitre      big update (see commit log for details)</i></b>
 <a name="L58" href="source/drivers/net/ethernet/smsc/smc91x.c#L58">58</a> <b><i> */</i></b>
 <a name="L59" href="source/drivers/net/ethernet/smsc/smc91x.c#L59">59</a> static const char <a href="ident?i=version">version</a>[] =
 <a name="L60" href="source/drivers/net/ethernet/smsc/smc91x.c#L60">60</a>         <i>"smc91x.c: v1.1, sep 22 2004 by Nicolas Pitre &lt;nico@fluxnic.net&gt;"</i>;
 <a name="L61" href="source/drivers/net/ethernet/smsc/smc91x.c#L61">61</a> 
 <a name="L62" href="source/drivers/net/ethernet/smsc/smc91x.c#L62">62</a> <b><i>/* Debugging level */</i></b>
 <a name="L63" href="source/drivers/net/ethernet/smsc/smc91x.c#L63">63</a> #ifndef <a href="ident?i=SMC_DEBUG">SMC_DEBUG</a>
 <a name="L64" href="source/drivers/net/ethernet/smsc/smc91x.c#L64">64</a> #define <a href="ident?i=SMC_DEBUG">SMC_DEBUG</a>               0
 <a name="L65" href="source/drivers/net/ethernet/smsc/smc91x.c#L65">65</a> #endif
 <a name="L66" href="source/drivers/net/ethernet/smsc/smc91x.c#L66">66</a> 
 <a name="L67" href="source/drivers/net/ethernet/smsc/smc91x.c#L67">67</a> 
 <a name="L68" href="source/drivers/net/ethernet/smsc/smc91x.c#L68">68</a> #include &lt;linux/module.h&gt;
 <a name="L69" href="source/drivers/net/ethernet/smsc/smc91x.c#L69">69</a> #include &lt;linux/kernel.h&gt;
 <a name="L70" href="source/drivers/net/ethernet/smsc/smc91x.c#L70">70</a> #include &lt;linux/sched.h&gt;
 <a name="L71" href="source/drivers/net/ethernet/smsc/smc91x.c#L71">71</a> #include &lt;linux/delay.h&gt;
 <a name="L72" href="source/drivers/net/ethernet/smsc/smc91x.c#L72">72</a> #include &lt;linux/interrupt.h&gt;
 <a name="L73" href="source/drivers/net/ethernet/smsc/smc91x.c#L73">73</a> #include &lt;linux/irq.h&gt;
 <a name="L74" href="source/drivers/net/ethernet/smsc/smc91x.c#L74">74</a> #include &lt;linux/errno.h&gt;
 <a name="L75" href="source/drivers/net/ethernet/smsc/smc91x.c#L75">75</a> #include &lt;linux/ioport.h&gt;
 <a name="L76" href="source/drivers/net/ethernet/smsc/smc91x.c#L76">76</a> #include &lt;linux/crc32.h&gt;
 <a name="L77" href="source/drivers/net/ethernet/smsc/smc91x.c#L77">77</a> #include &lt;linux/platform_device.h&gt;
 <a name="L78" href="source/drivers/net/ethernet/smsc/smc91x.c#L78">78</a> #include &lt;linux/spinlock.h&gt;
 <a name="L79" href="source/drivers/net/ethernet/smsc/smc91x.c#L79">79</a> #include &lt;linux/ethtool.h&gt;
 <a name="L80" href="source/drivers/net/ethernet/smsc/smc91x.c#L80">80</a> #include &lt;linux/mii.h&gt;
 <a name="L81" href="source/drivers/net/ethernet/smsc/smc91x.c#L81">81</a> #include &lt;linux/workqueue.h&gt;
 <a name="L82" href="source/drivers/net/ethernet/smsc/smc91x.c#L82">82</a> #include &lt;linux/of.h&gt;
 <a name="L83" href="source/drivers/net/ethernet/smsc/smc91x.c#L83">83</a> #include &lt;linux/of_device.h&gt;
 <a name="L84" href="source/drivers/net/ethernet/smsc/smc91x.c#L84">84</a> #include &lt;linux/of_gpio.h&gt;
 <a name="L85" href="source/drivers/net/ethernet/smsc/smc91x.c#L85">85</a> 
 <a name="L86" href="source/drivers/net/ethernet/smsc/smc91x.c#L86">86</a> #include &lt;linux/netdevice.h&gt;
 <a name="L87" href="source/drivers/net/ethernet/smsc/smc91x.c#L87">87</a> #include &lt;linux/etherdevice.h&gt;
 <a name="L88" href="source/drivers/net/ethernet/smsc/smc91x.c#L88">88</a> #include &lt;linux/skbuff.h&gt;
 <a name="L89" href="source/drivers/net/ethernet/smsc/smc91x.c#L89">89</a> 
 <a name="L90" href="source/drivers/net/ethernet/smsc/smc91x.c#L90">90</a> #include &lt;asm/io.h&gt;
 <a name="L91" href="source/drivers/net/ethernet/smsc/smc91x.c#L91">91</a> 
 <a name="L92" href="source/drivers/net/ethernet/smsc/smc91x.c#L92">92</a> #include "<a href="source/drivers/net/ethernet/smsc/smc91x.h">smc91x.h</a>"
 <a name="L93" href="source/drivers/net/ethernet/smsc/smc91x.c#L93">93</a> 
 <a name="L94" href="source/drivers/net/ethernet/smsc/smc91x.c#L94">94</a> #if defined(CONFIG_ASSABET_NEPONSET)
 <a name="L95" href="source/drivers/net/ethernet/smsc/smc91x.c#L95">95</a> #include &lt;mach/assabet.h&gt;
 <a name="L96" href="source/drivers/net/ethernet/smsc/smc91x.c#L96">96</a> #include &lt;mach/neponset.h&gt;
 <a name="L97" href="source/drivers/net/ethernet/smsc/smc91x.c#L97">97</a> #endif
 <a name="L98" href="source/drivers/net/ethernet/smsc/smc91x.c#L98">98</a> 
 <a name="L99" href="source/drivers/net/ethernet/smsc/smc91x.c#L99">99</a> #ifndef <a href="ident?i=SMC_NOWAIT">SMC_NOWAIT</a>
<a name="L100" href="source/drivers/net/ethernet/smsc/smc91x.c#L100">100</a> # define <a href="ident?i=SMC_NOWAIT">SMC_NOWAIT</a>             0
<a name="L101" href="source/drivers/net/ethernet/smsc/smc91x.c#L101">101</a> #endif
<a name="L102" href="source/drivers/net/ethernet/smsc/smc91x.c#L102">102</a> static int <a href="ident?i=nowait">nowait</a> = <a href="ident?i=SMC_NOWAIT">SMC_NOWAIT</a>;
<a name="L103" href="source/drivers/net/ethernet/smsc/smc91x.c#L103">103</a> <a href="ident?i=module_param">module_param</a>(<a href="ident?i=nowait">nowait</a>, int, 0400);
<a name="L104" href="source/drivers/net/ethernet/smsc/smc91x.c#L104">104</a> <a href="ident?i=MODULE_PARM_DESC">MODULE_PARM_DESC</a>(<a href="ident?i=nowait">nowait</a>, <i>"set to 1 for no wait state"</i>);
<a name="L105" href="source/drivers/net/ethernet/smsc/smc91x.c#L105">105</a> 
<a name="L106" href="source/drivers/net/ethernet/smsc/smc91x.c#L106">106</a> <b><i>/*</i></b>
<a name="L107" href="source/drivers/net/ethernet/smsc/smc91x.c#L107">107</a> <b><i> * Transmit timeout, default 5 seconds.</i></b>
<a name="L108" href="source/drivers/net/ethernet/smsc/smc91x.c#L108">108</a> <b><i> */</i></b>
<a name="L109" href="source/drivers/net/ethernet/smsc/smc91x.c#L109">109</a> static int <a href="ident?i=watchdog">watchdog</a> = 1000;
<a name="L110" href="source/drivers/net/ethernet/smsc/smc91x.c#L110">110</a> <a href="ident?i=module_param">module_param</a>(<a href="ident?i=watchdog">watchdog</a>, int, 0400);
<a name="L111" href="source/drivers/net/ethernet/smsc/smc91x.c#L111">111</a> <a href="ident?i=MODULE_PARM_DESC">MODULE_PARM_DESC</a>(<a href="ident?i=watchdog">watchdog</a>, <i>"transmit timeout in milliseconds"</i>);
<a name="L112" href="source/drivers/net/ethernet/smsc/smc91x.c#L112">112</a> 
<a name="L113" href="source/drivers/net/ethernet/smsc/smc91x.c#L113">113</a> <a href="ident?i=MODULE_LICENSE">MODULE_LICENSE</a>(<i>"GPL"</i>);
<a name="L114" href="source/drivers/net/ethernet/smsc/smc91x.c#L114">114</a> <a href="ident?i=MODULE_ALIAS">MODULE_ALIAS</a>(<i>"platform:smc91x"</i>);
<a name="L115" href="source/drivers/net/ethernet/smsc/smc91x.c#L115">115</a> 
<a name="L116" href="source/drivers/net/ethernet/smsc/smc91x.c#L116">116</a> <b><i>/*</i></b>
<a name="L117" href="source/drivers/net/ethernet/smsc/smc91x.c#L117">117</a> <b><i> * The internal workings of the driver.  If you are changing anything</i></b>
<a name="L118" href="source/drivers/net/ethernet/smsc/smc91x.c#L118">118</a> <b><i> * here with the SMC stuff, you should have the datasheet and know</i></b>
<a name="L119" href="source/drivers/net/ethernet/smsc/smc91x.c#L119">119</a> <b><i> * what you are doing.</i></b>
<a name="L120" href="source/drivers/net/ethernet/smsc/smc91x.c#L120">120</a> <b><i> */</i></b>
<a name="L121" href="source/drivers/net/ethernet/smsc/smc91x.c#L121">121</a> #define <a href="ident?i=CARDNAME">CARDNAME</a> <i>"smc91x"</i>
<a name="L122" href="source/drivers/net/ethernet/smsc/smc91x.c#L122">122</a> 
<a name="L123" href="source/drivers/net/ethernet/smsc/smc91x.c#L123">123</a> <b><i>/*</i></b>
<a name="L124" href="source/drivers/net/ethernet/smsc/smc91x.c#L124">124</a> <b><i> * Use power-down feature of the chip</i></b>
<a name="L125" href="source/drivers/net/ethernet/smsc/smc91x.c#L125">125</a> <b><i> */</i></b>
<a name="L126" href="source/drivers/net/ethernet/smsc/smc91x.c#L126">126</a> #define <a href="ident?i=POWER_DOWN">POWER_DOWN</a>              1
<a name="L127" href="source/drivers/net/ethernet/smsc/smc91x.c#L127">127</a> 
<a name="L128" href="source/drivers/net/ethernet/smsc/smc91x.c#L128">128</a> <b><i>/*</i></b>
<a name="L129" href="source/drivers/net/ethernet/smsc/smc91x.c#L129">129</a> <b><i> * Wait time for memory to be free.  This probably shouldn't be</i></b>
<a name="L130" href="source/drivers/net/ethernet/smsc/smc91x.c#L130">130</a> <b><i> * tuned that much, as waiting for this means nothing else happens</i></b>
<a name="L131" href="source/drivers/net/ethernet/smsc/smc91x.c#L131">131</a> <b><i> * in the system</i></b>
<a name="L132" href="source/drivers/net/ethernet/smsc/smc91x.c#L132">132</a> <b><i> */</i></b>
<a name="L133" href="source/drivers/net/ethernet/smsc/smc91x.c#L133">133</a> #define <a href="ident?i=MEMORY_WAIT_TIME">MEMORY_WAIT_TIME</a>        16
<a name="L134" href="source/drivers/net/ethernet/smsc/smc91x.c#L134">134</a> 
<a name="L135" href="source/drivers/net/ethernet/smsc/smc91x.c#L135">135</a> <b><i>/*</i></b>
<a name="L136" href="source/drivers/net/ethernet/smsc/smc91x.c#L136">136</a> <b><i> * The maximum number of processing loops allowed for each call to the</i></b>
<a name="L137" href="source/drivers/net/ethernet/smsc/smc91x.c#L137">137</a> <b><i> * IRQ handler.</i></b>
<a name="L138" href="source/drivers/net/ethernet/smsc/smc91x.c#L138">138</a> <b><i> */</i></b>
<a name="L139" href="source/drivers/net/ethernet/smsc/smc91x.c#L139">139</a> #define <a href="ident?i=MAX_IRQ_LOOPS">MAX_IRQ_LOOPS</a>           8
<a name="L140" href="source/drivers/net/ethernet/smsc/smc91x.c#L140">140</a> 
<a name="L141" href="source/drivers/net/ethernet/smsc/smc91x.c#L141">141</a> <b><i>/*</i></b>
<a name="L142" href="source/drivers/net/ethernet/smsc/smc91x.c#L142">142</a> <b><i> * This selects whether TX packets are sent one by one to the SMC91x internal</i></b>
<a name="L143" href="source/drivers/net/ethernet/smsc/smc91x.c#L143">143</a> <b><i> * memory and throttled until transmission completes.  This may prevent</i></b>
<a name="L144" href="source/drivers/net/ethernet/smsc/smc91x.c#L144">144</a> <b><i> * RX overruns a litle by keeping much of the memory free for RX packets</i></b>
<a name="L145" href="source/drivers/net/ethernet/smsc/smc91x.c#L145">145</a> <b><i> * but to the expense of reduced TX throughput and increased IRQ overhead.</i></b>
<a name="L146" href="source/drivers/net/ethernet/smsc/smc91x.c#L146">146</a> <b><i> * Note this is not a cure for a too slow data bus or too high IRQ latency.</i></b>
<a name="L147" href="source/drivers/net/ethernet/smsc/smc91x.c#L147">147</a> <b><i> */</i></b>
<a name="L148" href="source/drivers/net/ethernet/smsc/smc91x.c#L148">148</a> #define <a href="ident?i=THROTTLE_TX_PKTS">THROTTLE_TX_PKTS</a>        0
<a name="L149" href="source/drivers/net/ethernet/smsc/smc91x.c#L149">149</a> 
<a name="L150" href="source/drivers/net/ethernet/smsc/smc91x.c#L150">150</a> <b><i>/*</i></b>
<a name="L151" href="source/drivers/net/ethernet/smsc/smc91x.c#L151">151</a> <b><i> * The MII clock high/low times.  2x this number gives the MII clock period</i></b>
<a name="L152" href="source/drivers/net/ethernet/smsc/smc91x.c#L152">152</a> <b><i> * in microseconds. (was 50, but this gives 6.4ms for each MII transaction!)</i></b>
<a name="L153" href="source/drivers/net/ethernet/smsc/smc91x.c#L153">153</a> <b><i> */</i></b>
<a name="L154" href="source/drivers/net/ethernet/smsc/smc91x.c#L154">154</a> #define <a href="ident?i=MII_DELAY">MII_DELAY</a>               1
<a name="L155" href="source/drivers/net/ethernet/smsc/smc91x.c#L155">155</a> 
<a name="L156" href="source/drivers/net/ethernet/smsc/smc91x.c#L156">156</a> #define <a href="ident?i=DBG">DBG</a>(<a href="ident?i=n">n</a>, <a href="ident?i=dev">dev</a>, <a href="ident?i=fmt">fmt</a>, ...)                                   \
<a name="L157" href="source/drivers/net/ethernet/smsc/smc91x.c#L157">157</a>         do {                                                    \
<a name="L158" href="source/drivers/net/ethernet/smsc/smc91x.c#L158">158</a>                 if (<a href="ident?i=SMC_DEBUG">SMC_DEBUG</a> &gt;= (<a href="ident?i=n">n</a>))                           \
<a name="L159" href="source/drivers/net/ethernet/smsc/smc91x.c#L159">159</a>                         <a href="ident?i=netdev_dbg">netdev_dbg</a>(<a href="ident?i=dev">dev</a>, <a href="ident?i=fmt">fmt</a>, ##__VA_ARGS__);    \
<a name="L160" href="source/drivers/net/ethernet/smsc/smc91x.c#L160">160</a>         } while (0)
<a name="L161" href="source/drivers/net/ethernet/smsc/smc91x.c#L161">161</a> 
<a name="L162" href="source/drivers/net/ethernet/smsc/smc91x.c#L162">162</a> #define <a href="ident?i=PRINTK">PRINTK</a>(<a href="ident?i=dev">dev</a>, <a href="ident?i=fmt">fmt</a>, ...)                                   \
<a name="L163" href="source/drivers/net/ethernet/smsc/smc91x.c#L163">163</a>         do {                                                    \
<a name="L164" href="source/drivers/net/ethernet/smsc/smc91x.c#L164">164</a>                 if (<a href="ident?i=SMC_DEBUG">SMC_DEBUG</a> &gt; 0)                              \
<a name="L165" href="source/drivers/net/ethernet/smsc/smc91x.c#L165">165</a>                         <a href="ident?i=netdev_info">netdev_info</a>(<a href="ident?i=dev">dev</a>, <a href="ident?i=fmt">fmt</a>, ##__VA_ARGS__);   \
<a name="L166" href="source/drivers/net/ethernet/smsc/smc91x.c#L166">166</a>                 else                                            \
<a name="L167" href="source/drivers/net/ethernet/smsc/smc91x.c#L167">167</a>                         <a href="ident?i=netdev_dbg">netdev_dbg</a>(<a href="ident?i=dev">dev</a>, <a href="ident?i=fmt">fmt</a>, ##__VA_ARGS__);    \
<a name="L168" href="source/drivers/net/ethernet/smsc/smc91x.c#L168">168</a>         } while (0)
<a name="L169" href="source/drivers/net/ethernet/smsc/smc91x.c#L169">169</a> 
<a name="L170" href="source/drivers/net/ethernet/smsc/smc91x.c#L170">170</a> #if <a href="ident?i=SMC_DEBUG">SMC_DEBUG</a> &gt; 3
<a name="L171" href="source/drivers/net/ethernet/smsc/smc91x.c#L171">171</a> static void <a href="ident?i=PRINT_PKT">PRINT_PKT</a>(<a href="ident?i=u_char">u_char</a> *<a href="ident?i=buf">buf</a>, int <a href="ident?i=length">length</a>)
<a name="L172" href="source/drivers/net/ethernet/smsc/smc91x.c#L172">172</a> {
<a name="L173" href="source/drivers/net/ethernet/smsc/smc91x.c#L173">173</a>         int <a href="ident?i=i">i</a>;
<a name="L174" href="source/drivers/net/ethernet/smsc/smc91x.c#L174">174</a>         int remainder;
<a name="L175" href="source/drivers/net/ethernet/smsc/smc91x.c#L175">175</a>         int <a href="ident?i=lines">lines</a>;
<a name="L176" href="source/drivers/net/ethernet/smsc/smc91x.c#L176">176</a> 
<a name="L177" href="source/drivers/net/ethernet/smsc/smc91x.c#L177">177</a>         <a href="ident?i=lines">lines</a> = <a href="ident?i=length">length</a> / 16;
<a name="L178" href="source/drivers/net/ethernet/smsc/smc91x.c#L178">178</a>         remainder = <a href="ident?i=length">length</a> % 16;
<a name="L179" href="source/drivers/net/ethernet/smsc/smc91x.c#L179">179</a> 
<a name="L180" href="source/drivers/net/ethernet/smsc/smc91x.c#L180">180</a>         for (<a href="ident?i=i">i</a> = 0; <a href="ident?i=i">i</a> &lt; <a href="ident?i=lines">lines</a> ; <a href="ident?i=i">i</a> ++) {
<a name="L181" href="source/drivers/net/ethernet/smsc/smc91x.c#L181">181</a>                 int cur;
<a name="L182" href="source/drivers/net/ethernet/smsc/smc91x.c#L182">182</a>                 <a href="ident?i=printk">printk</a>(<a href="ident?i=KERN_DEBUG">KERN_DEBUG</a>);
<a name="L183" href="source/drivers/net/ethernet/smsc/smc91x.c#L183">183</a>                 for (cur = 0; cur &lt; 8; cur++) {
<a name="L184" href="source/drivers/net/ethernet/smsc/smc91x.c#L184">184</a>                         <a href="ident?i=u_char">u_char</a> <a href="ident?i=a">a</a>, <a href="ident?i=b">b</a>;
<a name="L185" href="source/drivers/net/ethernet/smsc/smc91x.c#L185">185</a>                         <a href="ident?i=a">a</a> = *<a href="ident?i=buf">buf</a>++;
<a name="L186" href="source/drivers/net/ethernet/smsc/smc91x.c#L186">186</a>                         <a href="ident?i=b">b</a> = *<a href="ident?i=buf">buf</a>++;
<a name="L187" href="source/drivers/net/ethernet/smsc/smc91x.c#L187">187</a>                         <a href="ident?i=pr_cont">pr_cont</a>(<i>"%02x%02x "</i>, <a href="ident?i=a">a</a>, <a href="ident?i=b">b</a>);
<a name="L188" href="source/drivers/net/ethernet/smsc/smc91x.c#L188">188</a>                 }
<a name="L189" href="source/drivers/net/ethernet/smsc/smc91x.c#L189">189</a>                 <a href="ident?i=pr_cont">pr_cont</a>(<i>"\n"</i>);
<a name="L190" href="source/drivers/net/ethernet/smsc/smc91x.c#L190">190</a>         }
<a name="L191" href="source/drivers/net/ethernet/smsc/smc91x.c#L191">191</a>         <a href="ident?i=printk">printk</a>(<a href="ident?i=KERN_DEBUG">KERN_DEBUG</a>);
<a name="L192" href="source/drivers/net/ethernet/smsc/smc91x.c#L192">192</a>         for (<a href="ident?i=i">i</a> = 0; <a href="ident?i=i">i</a> &lt; remainder/2 ; <a href="ident?i=i">i</a>++) {
<a name="L193" href="source/drivers/net/ethernet/smsc/smc91x.c#L193">193</a>                 <a href="ident?i=u_char">u_char</a> <a href="ident?i=a">a</a>, <a href="ident?i=b">b</a>;
<a name="L194" href="source/drivers/net/ethernet/smsc/smc91x.c#L194">194</a>                 <a href="ident?i=a">a</a> = *<a href="ident?i=buf">buf</a>++;
<a name="L195" href="source/drivers/net/ethernet/smsc/smc91x.c#L195">195</a>                 <a href="ident?i=b">b</a> = *<a href="ident?i=buf">buf</a>++;
<a name="L196" href="source/drivers/net/ethernet/smsc/smc91x.c#L196">196</a>                 <a href="ident?i=pr_cont">pr_cont</a>(<i>"%02x%02x "</i>, <a href="ident?i=a">a</a>, <a href="ident?i=b">b</a>);
<a name="L197" href="source/drivers/net/ethernet/smsc/smc91x.c#L197">197</a>         }
<a name="L198" href="source/drivers/net/ethernet/smsc/smc91x.c#L198">198</a>         <a href="ident?i=pr_cont">pr_cont</a>(<i>"\n"</i>);
<a name="L199" href="source/drivers/net/ethernet/smsc/smc91x.c#L199">199</a> }
<a name="L200" href="source/drivers/net/ethernet/smsc/smc91x.c#L200">200</a> #else
<a name="L201" href="source/drivers/net/ethernet/smsc/smc91x.c#L201">201</a> static inline void <a href="ident?i=PRINT_PKT">PRINT_PKT</a>(<a href="ident?i=u_char">u_char</a> *<a href="ident?i=buf">buf</a>, int <a href="ident?i=length">length</a>) { }
<a name="L202" href="source/drivers/net/ethernet/smsc/smc91x.c#L202">202</a> #endif
<a name="L203" href="source/drivers/net/ethernet/smsc/smc91x.c#L203">203</a> 
<a name="L204" href="source/drivers/net/ethernet/smsc/smc91x.c#L204">204</a> 
<a name="L205" href="source/drivers/net/ethernet/smsc/smc91x.c#L205">205</a> <b><i>/* this enables an interrupt in the interrupt mask register */</i></b>
<a name="L206" href="source/drivers/net/ethernet/smsc/smc91x.c#L206">206</a> #define <a href="ident?i=SMC_ENABLE_INT">SMC_ENABLE_INT</a>(<a href="ident?i=lp">lp</a>, <a href="ident?i=x">x</a>) do {                                      \
<a name="L207" href="source/drivers/net/ethernet/smsc/smc91x.c#L207">207</a>         unsigned char <a href="ident?i=mask">mask</a>;                                             \
<a name="L208" href="source/drivers/net/ethernet/smsc/smc91x.c#L208">208</a>         unsigned long smc_enable_flags;                                 \
<a name="L209" href="source/drivers/net/ethernet/smsc/smc91x.c#L209">209</a>         <a href="ident?i=spin_lock_irqsave">spin_lock_irqsave</a>(&amp;<a href="ident?i=lp">lp</a>-&gt;<a href="ident?i=lock">lock</a>, smc_enable_flags);                 \
<a name="L210" href="source/drivers/net/ethernet/smsc/smc91x.c#L210">210</a>         <a href="ident?i=mask">mask</a> = <a href="ident?i=SMC_GET_INT_MASK">SMC_GET_INT_MASK</a>(<a href="ident?i=lp">lp</a>);                                    \
<a name="L211" href="source/drivers/net/ethernet/smsc/smc91x.c#L211">211</a>         <a href="ident?i=mask">mask</a> |= (<a href="ident?i=x">x</a>);                                                    \
<a name="L212" href="source/drivers/net/ethernet/smsc/smc91x.c#L212">212</a>         <a href="ident?i=SMC_SET_INT_MASK">SMC_SET_INT_MASK</a>(<a href="ident?i=lp">lp</a>, <a href="ident?i=mask">mask</a>);                                     \
<a name="L213" href="source/drivers/net/ethernet/smsc/smc91x.c#L213">213</a>         <a href="ident?i=spin_unlock_irqrestore">spin_unlock_irqrestore</a>(&amp;<a href="ident?i=lp">lp</a>-&gt;<a href="ident?i=lock">lock</a>, smc_enable_flags);            \
<a name="L214" href="source/drivers/net/ethernet/smsc/smc91x.c#L214">214</a> } while (0)
<a name="L215" href="source/drivers/net/ethernet/smsc/smc91x.c#L215">215</a> 
<a name="L216" href="source/drivers/net/ethernet/smsc/smc91x.c#L216">216</a> <b><i>/* this disables an interrupt from the interrupt mask register */</i></b>
<a name="L217" href="source/drivers/net/ethernet/smsc/smc91x.c#L217">217</a> #define <a href="ident?i=SMC_DISABLE_INT">SMC_DISABLE_INT</a>(<a href="ident?i=lp">lp</a>, <a href="ident?i=x">x</a>) do {                                     \
<a name="L218" href="source/drivers/net/ethernet/smsc/smc91x.c#L218">218</a>         unsigned char <a href="ident?i=mask">mask</a>;                                             \
<a name="L219" href="source/drivers/net/ethernet/smsc/smc91x.c#L219">219</a>         unsigned long smc_disable_flags;                                \
<a name="L220" href="source/drivers/net/ethernet/smsc/smc91x.c#L220">220</a>         <a href="ident?i=spin_lock_irqsave">spin_lock_irqsave</a>(&amp;<a href="ident?i=lp">lp</a>-&gt;<a href="ident?i=lock">lock</a>, smc_disable_flags);                \
<a name="L221" href="source/drivers/net/ethernet/smsc/smc91x.c#L221">221</a>         <a href="ident?i=mask">mask</a> = <a href="ident?i=SMC_GET_INT_MASK">SMC_GET_INT_MASK</a>(<a href="ident?i=lp">lp</a>);                                    \
<a name="L222" href="source/drivers/net/ethernet/smsc/smc91x.c#L222">222</a>         <a href="ident?i=mask">mask</a> &amp;= ~(<a href="ident?i=x">x</a>);                                                   \
<a name="L223" href="source/drivers/net/ethernet/smsc/smc91x.c#L223">223</a>         <a href="ident?i=SMC_SET_INT_MASK">SMC_SET_INT_MASK</a>(<a href="ident?i=lp">lp</a>, <a href="ident?i=mask">mask</a>);                                     \
<a name="L224" href="source/drivers/net/ethernet/smsc/smc91x.c#L224">224</a>         <a href="ident?i=spin_unlock_irqrestore">spin_unlock_irqrestore</a>(&amp;<a href="ident?i=lp">lp</a>-&gt;<a href="ident?i=lock">lock</a>, smc_disable_flags);           \
<a name="L225" href="source/drivers/net/ethernet/smsc/smc91x.c#L225">225</a> } while (0)
<a name="L226" href="source/drivers/net/ethernet/smsc/smc91x.c#L226">226</a> 
<a name="L227" href="source/drivers/net/ethernet/smsc/smc91x.c#L227">227</a> <b><i>/*</i></b>
<a name="L228" href="source/drivers/net/ethernet/smsc/smc91x.c#L228">228</a> <b><i> * Wait while MMU is busy.  This is usually in the order of a few nanosecs</i></b>
<a name="L229" href="source/drivers/net/ethernet/smsc/smc91x.c#L229">229</a> <b><i> * if at all, but let's avoid deadlocking the system if the hardware</i></b>
<a name="L230" href="source/drivers/net/ethernet/smsc/smc91x.c#L230">230</a> <b><i> * decides to go south.</i></b>
<a name="L231" href="source/drivers/net/ethernet/smsc/smc91x.c#L231">231</a> <b><i> */</i></b>
<a name="L232" href="source/drivers/net/ethernet/smsc/smc91x.c#L232">232</a> #define <a href="ident?i=SMC_WAIT_MMU_BUSY">SMC_WAIT_MMU_BUSY</a>(<a href="ident?i=lp">lp</a>) do {                                      \
<a name="L233" href="source/drivers/net/ethernet/smsc/smc91x.c#L233">233</a>         if (<a href="ident?i=unlikely">unlikely</a>(<a href="ident?i=SMC_GET_MMU_CMD">SMC_GET_MMU_CMD</a>(<a href="ident?i=lp">lp</a>) &amp; <a href="ident?i=MC_BUSY">MC_BUSY</a>)) {          \
<a name="L234" href="source/drivers/net/ethernet/smsc/smc91x.c#L234">234</a>                 unsigned long <a href="ident?i=timeout">timeout</a> = <a href="ident?i=jiffies">jiffies</a> + 2;                    \
<a name="L235" href="source/drivers/net/ethernet/smsc/smc91x.c#L235">235</a>                 while (<a href="ident?i=SMC_GET_MMU_CMD">SMC_GET_MMU_CMD</a>(<a href="ident?i=lp">lp</a>) &amp; <a href="ident?i=MC_BUSY">MC_BUSY</a>) {         \
<a name="L236" href="source/drivers/net/ethernet/smsc/smc91x.c#L236">236</a>                         if (<a href="ident?i=time_after">time_after</a>(<a href="ident?i=jiffies">jiffies</a>, <a href="ident?i=timeout">timeout</a>)) {             \
<a name="L237" href="source/drivers/net/ethernet/smsc/smc91x.c#L237">237</a>                                 <a href="ident?i=netdev_dbg">netdev_dbg</a>(<a href="ident?i=dev">dev</a>, <i>"timeout %s line %d\n"</i>, \
<a name="L238" href="source/drivers/net/ethernet/smsc/smc91x.c#L238">238</a>                                            __FILE__, <a href="ident?i=__LINE__">__LINE__</a>);         \
<a name="L239" href="source/drivers/net/ethernet/smsc/smc91x.c#L239">239</a>                                 break;                                  \
<a name="L240" href="source/drivers/net/ethernet/smsc/smc91x.c#L240">240</a>                         }                                               \
<a name="L241" href="source/drivers/net/ethernet/smsc/smc91x.c#L241">241</a>                         <a href="ident?i=cpu_relax">cpu_relax</a>();                                    \
<a name="L242" href="source/drivers/net/ethernet/smsc/smc91x.c#L242">242</a>                 }                                                       \
<a name="L243" href="source/drivers/net/ethernet/smsc/smc91x.c#L243">243</a>         }                                                               \
<a name="L244" href="source/drivers/net/ethernet/smsc/smc91x.c#L244">244</a> } while (0)
<a name="L245" href="source/drivers/net/ethernet/smsc/smc91x.c#L245">245</a> 
<a name="L246" href="source/drivers/net/ethernet/smsc/smc91x.c#L246">246</a> 
<a name="L247" href="source/drivers/net/ethernet/smsc/smc91x.c#L247">247</a> <b><i>/*</i></b>
<a name="L248" href="source/drivers/net/ethernet/smsc/smc91x.c#L248">248</a> <b><i> * this does a soft reset on the device</i></b>
<a name="L249" href="source/drivers/net/ethernet/smsc/smc91x.c#L249">249</a> <b><i> */</i></b>
<a name="L250" href="source/drivers/net/ethernet/smsc/smc91x.c#L250">250</a> static void <a href="ident?i=smc_reset">smc_reset</a>(struct <a href="ident?i=net_device">net_device</a> *<a href="ident?i=dev">dev</a>)
<a name="L251" href="source/drivers/net/ethernet/smsc/smc91x.c#L251">251</a> {
<a name="L252" href="source/drivers/net/ethernet/smsc/smc91x.c#L252">252</a>         struct <a href="ident?i=smc_local">smc_local</a> *<a href="ident?i=lp">lp</a> = <a href="ident?i=netdev_priv">netdev_priv</a>(<a href="ident?i=dev">dev</a>);
<a name="L253" href="source/drivers/net/ethernet/smsc/smc91x.c#L253">253</a>         void <a href="ident?i=__iomem">__iomem</a> *<a href="ident?i=ioaddr">ioaddr</a> = <a href="ident?i=lp">lp</a>-&gt;<a href="ident?i=base">base</a>;
<a name="L254" href="source/drivers/net/ethernet/smsc/smc91x.c#L254">254</a>         unsigned int <a href="ident?i=ctl">ctl</a>, <a href="ident?i=cfg">cfg</a>;
<a name="L255" href="source/drivers/net/ethernet/smsc/smc91x.c#L255">255</a>         struct <a href="ident?i=sk_buff">sk_buff</a> *pending_skb;
<a name="L256" href="source/drivers/net/ethernet/smsc/smc91x.c#L256">256</a> 
<a name="L257" href="source/drivers/net/ethernet/smsc/smc91x.c#L257">257</a>         <a href="ident?i=DBG">DBG</a>(2, <a href="ident?i=dev">dev</a>, <i>"%s\n"</i>, <a href="ident?i=__func__">__func__</a>);
<a name="L258" href="source/drivers/net/ethernet/smsc/smc91x.c#L258">258</a> 
<a name="L259" href="source/drivers/net/ethernet/smsc/smc91x.c#L259">259</a>         <b><i>/* Disable all interrupts, block TX tasklet */</i></b>
<a name="L260" href="source/drivers/net/ethernet/smsc/smc91x.c#L260">260</a>         <a href="ident?i=spin_lock_irq">spin_lock_irq</a>(&amp;<a href="ident?i=lp">lp</a>-&gt;<a href="ident?i=lock">lock</a>);
<a name="L261" href="source/drivers/net/ethernet/smsc/smc91x.c#L261">261</a>         <a href="ident?i=SMC_SELECT_BANK">SMC_SELECT_BANK</a>(<a href="ident?i=lp">lp</a>, 2);
<a name="L262" href="source/drivers/net/ethernet/smsc/smc91x.c#L262">262</a>         <a href="ident?i=SMC_SET_INT_MASK">SMC_SET_INT_MASK</a>(<a href="ident?i=lp">lp</a>, 0);
<a name="L263" href="source/drivers/net/ethernet/smsc/smc91x.c#L263">263</a>         pending_skb = <a href="ident?i=lp">lp</a>-&gt;pending_tx_skb;
<a name="L264" href="source/drivers/net/ethernet/smsc/smc91x.c#L264">264</a>         <a href="ident?i=lp">lp</a>-&gt;pending_tx_skb = <a href="ident?i=NULL">NULL</a>;
<a name="L265" href="source/drivers/net/ethernet/smsc/smc91x.c#L265">265</a>         <a href="ident?i=spin_unlock_irq">spin_unlock_irq</a>(&amp;<a href="ident?i=lp">lp</a>-&gt;<a href="ident?i=lock">lock</a>);
<a name="L266" href="source/drivers/net/ethernet/smsc/smc91x.c#L266">266</a> 
<a name="L267" href="source/drivers/net/ethernet/smsc/smc91x.c#L267">267</a>         <b><i>/* free any pending tx skb */</i></b>
<a name="L268" href="source/drivers/net/ethernet/smsc/smc91x.c#L268">268</a>         if (pending_skb) {
<a name="L269" href="source/drivers/net/ethernet/smsc/smc91x.c#L269">269</a>                 <a href="ident?i=dev_kfree_skb">dev_kfree_skb</a>(pending_skb);
<a name="L270" href="source/drivers/net/ethernet/smsc/smc91x.c#L270">270</a>                 <a href="ident?i=dev">dev</a>-&gt;<a href="ident?i=stats">stats</a>.tx_errors++;
<a name="L271" href="source/drivers/net/ethernet/smsc/smc91x.c#L271">271</a>                 <a href="ident?i=dev">dev</a>-&gt;<a href="ident?i=stats">stats</a>.tx_aborted_errors++;
<a name="L272" href="source/drivers/net/ethernet/smsc/smc91x.c#L272">272</a>         }
<a name="L273" href="source/drivers/net/ethernet/smsc/smc91x.c#L273">273</a> 
<a name="L274" href="source/drivers/net/ethernet/smsc/smc91x.c#L274">274</a>         <b><i>/*</i></b>
<a name="L275" href="source/drivers/net/ethernet/smsc/smc91x.c#L275">275</a> <b><i>         * This resets the registers mostly to defaults, but doesn't</i></b>
<a name="L276" href="source/drivers/net/ethernet/smsc/smc91x.c#L276">276</a> <b><i>         * affect EEPROM.  That seems unnecessary</i></b>
<a name="L277" href="source/drivers/net/ethernet/smsc/smc91x.c#L277">277</a> <b><i>         */</i></b>
<a name="L278" href="source/drivers/net/ethernet/smsc/smc91x.c#L278">278</a>         <a href="ident?i=SMC_SELECT_BANK">SMC_SELECT_BANK</a>(<a href="ident?i=lp">lp</a>, 0);
<a name="L279" href="source/drivers/net/ethernet/smsc/smc91x.c#L279">279</a>         <a href="ident?i=SMC_SET_RCR">SMC_SET_RCR</a>(<a href="ident?i=lp">lp</a>, <a href="ident?i=RCR_SOFTRST">RCR_SOFTRST</a>);
<a name="L280" href="source/drivers/net/ethernet/smsc/smc91x.c#L280">280</a> 
<a name="L281" href="source/drivers/net/ethernet/smsc/smc91x.c#L281">281</a>         <b><i>/*</i></b>
<a name="L282" href="source/drivers/net/ethernet/smsc/smc91x.c#L282">282</a> <b><i>         * Setup the Configuration Register</i></b>
<a name="L283" href="source/drivers/net/ethernet/smsc/smc91x.c#L283">283</a> <b><i>         * This is necessary because the CONFIG_REG is not affected</i></b>
<a name="L284" href="source/drivers/net/ethernet/smsc/smc91x.c#L284">284</a> <b><i>         * by a soft reset</i></b>
<a name="L285" href="source/drivers/net/ethernet/smsc/smc91x.c#L285">285</a> <b><i>         */</i></b>
<a name="L286" href="source/drivers/net/ethernet/smsc/smc91x.c#L286">286</a>         <a href="ident?i=SMC_SELECT_BANK">SMC_SELECT_BANK</a>(<a href="ident?i=lp">lp</a>, 1);
<a name="L287" href="source/drivers/net/ethernet/smsc/smc91x.c#L287">287</a> 
<a name="L288" href="source/drivers/net/ethernet/smsc/smc91x.c#L288">288</a>         <a href="ident?i=cfg">cfg</a> = <a href="ident?i=CONFIG_DEFAULT">CONFIG_DEFAULT</a>;
<a name="L289" href="source/drivers/net/ethernet/smsc/smc91x.c#L289">289</a> 
<a name="L290" href="source/drivers/net/ethernet/smsc/smc91x.c#L290">290</a>         <b><i>/*</i></b>
<a name="L291" href="source/drivers/net/ethernet/smsc/smc91x.c#L291">291</a> <b><i>         * Setup for fast accesses if requested.  If the card/system</i></b>
<a name="L292" href="source/drivers/net/ethernet/smsc/smc91x.c#L292">292</a> <b><i>         * can't handle it then there will be no recovery except for</i></b>
<a name="L293" href="source/drivers/net/ethernet/smsc/smc91x.c#L293">293</a> <b><i>         * a hard reset or power cycle</i></b>
<a name="L294" href="source/drivers/net/ethernet/smsc/smc91x.c#L294">294</a> <b><i>         */</i></b>
<a name="L295" href="source/drivers/net/ethernet/smsc/smc91x.c#L295">295</a>         if (<a href="ident?i=lp">lp</a>-&gt;<a href="ident?i=cfg">cfg</a>.<a href="ident?i=flags">flags</a> &amp; <a href="ident?i=SMC91X_NOWAIT">SMC91X_NOWAIT</a>)
<a name="L296" href="source/drivers/net/ethernet/smsc/smc91x.c#L296">296</a>                 <a href="ident?i=cfg">cfg</a> |= <a href="ident?i=CONFIG_NO_WAIT">CONFIG_NO_WAIT</a>;
<a name="L297" href="source/drivers/net/ethernet/smsc/smc91x.c#L297">297</a> 
<a name="L298" href="source/drivers/net/ethernet/smsc/smc91x.c#L298">298</a>         <b><i>/*</i></b>
<a name="L299" href="source/drivers/net/ethernet/smsc/smc91x.c#L299">299</a> <b><i>         * Release from possible power-down state</i></b>
<a name="L300" href="source/drivers/net/ethernet/smsc/smc91x.c#L300">300</a> <b><i>         * Configuration register is not affected by Soft Reset</i></b>
<a name="L301" href="source/drivers/net/ethernet/smsc/smc91x.c#L301">301</a> <b><i>         */</i></b>
<a name="L302" href="source/drivers/net/ethernet/smsc/smc91x.c#L302">302</a>         <a href="ident?i=cfg">cfg</a> |= <a href="ident?i=CONFIG_EPH_POWER_EN">CONFIG_EPH_POWER_EN</a>;
<a name="L303" href="source/drivers/net/ethernet/smsc/smc91x.c#L303">303</a> 
<a name="L304" href="source/drivers/net/ethernet/smsc/smc91x.c#L304">304</a>         <a href="ident?i=SMC_SET_CONFIG">SMC_SET_CONFIG</a>(<a href="ident?i=lp">lp</a>, <a href="ident?i=cfg">cfg</a>);
<a name="L305" href="source/drivers/net/ethernet/smsc/smc91x.c#L305">305</a> 
<a name="L306" href="source/drivers/net/ethernet/smsc/smc91x.c#L306">306</a>         <b><i>/* this should pause enough for the chip to be happy */</i></b>
<a name="L307" href="source/drivers/net/ethernet/smsc/smc91x.c#L307">307</a>         <b><i>/*</i></b>
<a name="L308" href="source/drivers/net/ethernet/smsc/smc91x.c#L308">308</a> <b><i>         * elaborate?  What does the chip _need_? --jgarzik</i></b>
<a name="L309" href="source/drivers/net/ethernet/smsc/smc91x.c#L309">309</a> <b><i>         *</i></b>
<a name="L310" href="source/drivers/net/ethernet/smsc/smc91x.c#L310">310</a> <b><i>         * This seems to be undocumented, but something the original</i></b>
<a name="L311" href="source/drivers/net/ethernet/smsc/smc91x.c#L311">311</a> <b><i>         * driver(s) have always done.  Suspect undocumented timing</i></b>
<a name="L312" href="source/drivers/net/ethernet/smsc/smc91x.c#L312">312</a> <b><i>         * info/determined empirically. --rmk</i></b>
<a name="L313" href="source/drivers/net/ethernet/smsc/smc91x.c#L313">313</a> <b><i>         */</i></b>
<a name="L314" href="source/drivers/net/ethernet/smsc/smc91x.c#L314">314</a>         <a href="ident?i=udelay">udelay</a>(1);
<a name="L315" href="source/drivers/net/ethernet/smsc/smc91x.c#L315">315</a> 
<a name="L316" href="source/drivers/net/ethernet/smsc/smc91x.c#L316">316</a>         <b><i>/* Disable transmit and receive functionality */</i></b>
<a name="L317" href="source/drivers/net/ethernet/smsc/smc91x.c#L317">317</a>         <a href="ident?i=SMC_SELECT_BANK">SMC_SELECT_BANK</a>(<a href="ident?i=lp">lp</a>, 0);
<a name="L318" href="source/drivers/net/ethernet/smsc/smc91x.c#L318">318</a>         <a href="ident?i=SMC_SET_RCR">SMC_SET_RCR</a>(<a href="ident?i=lp">lp</a>, <a href="ident?i=RCR_CLEAR">RCR_CLEAR</a>);
<a name="L319" href="source/drivers/net/ethernet/smsc/smc91x.c#L319">319</a>         <a href="ident?i=SMC_SET_TCR">SMC_SET_TCR</a>(<a href="ident?i=lp">lp</a>, <a href="ident?i=TCR_CLEAR">TCR_CLEAR</a>);
<a name="L320" href="source/drivers/net/ethernet/smsc/smc91x.c#L320">320</a> 
<a name="L321" href="source/drivers/net/ethernet/smsc/smc91x.c#L321">321</a>         <a href="ident?i=SMC_SELECT_BANK">SMC_SELECT_BANK</a>(<a href="ident?i=lp">lp</a>, 1);
<a name="L322" href="source/drivers/net/ethernet/smsc/smc91x.c#L322">322</a>         <a href="ident?i=ctl">ctl</a> = <a href="ident?i=SMC_GET_CTL">SMC_GET_CTL</a>(<a href="ident?i=lp">lp</a>) | <a href="ident?i=CTL_LE_ENABLE">CTL_LE_ENABLE</a>;
<a name="L323" href="source/drivers/net/ethernet/smsc/smc91x.c#L323">323</a> 
<a name="L324" href="source/drivers/net/ethernet/smsc/smc91x.c#L324">324</a>         <b><i>/*</i></b>
<a name="L325" href="source/drivers/net/ethernet/smsc/smc91x.c#L325">325</a> <b><i>         * Set the control register to automatically release successfully</i></b>
<a name="L326" href="source/drivers/net/ethernet/smsc/smc91x.c#L326">326</a> <b><i>         * transmitted packets, to make the best use out of our limited</i></b>
<a name="L327" href="source/drivers/net/ethernet/smsc/smc91x.c#L327">327</a> <b><i>         * memory</i></b>
<a name="L328" href="source/drivers/net/ethernet/smsc/smc91x.c#L328">328</a> <b><i>         */</i></b>
<a name="L329" href="source/drivers/net/ethernet/smsc/smc91x.c#L329">329</a>         if(!<a href="ident?i=THROTTLE_TX_PKTS">THROTTLE_TX_PKTS</a>)
<a name="L330" href="source/drivers/net/ethernet/smsc/smc91x.c#L330">330</a>                 <a href="ident?i=ctl">ctl</a> |= <a href="ident?i=CTL_AUTO_RELEASE">CTL_AUTO_RELEASE</a>;
<a name="L331" href="source/drivers/net/ethernet/smsc/smc91x.c#L331">331</a>         else
<a name="L332" href="source/drivers/net/ethernet/smsc/smc91x.c#L332">332</a>                 <a href="ident?i=ctl">ctl</a> &amp;= ~CTL_AUTO_RELEASE;
<a name="L333" href="source/drivers/net/ethernet/smsc/smc91x.c#L333">333</a>         <a href="ident?i=SMC_SET_CTL">SMC_SET_CTL</a>(<a href="ident?i=lp">lp</a>, <a href="ident?i=ctl">ctl</a>);
<a name="L334" href="source/drivers/net/ethernet/smsc/smc91x.c#L334">334</a> 
<a name="L335" href="source/drivers/net/ethernet/smsc/smc91x.c#L335">335</a>         <b><i>/* Reset the MMU */</i></b>
<a name="L336" href="source/drivers/net/ethernet/smsc/smc91x.c#L336">336</a>         <a href="ident?i=SMC_SELECT_BANK">SMC_SELECT_BANK</a>(<a href="ident?i=lp">lp</a>, 2);
<a name="L337" href="source/drivers/net/ethernet/smsc/smc91x.c#L337">337</a>         <a href="ident?i=SMC_SET_MMU_CMD">SMC_SET_MMU_CMD</a>(<a href="ident?i=lp">lp</a>, <a href="ident?i=MC_RESET">MC_RESET</a>);
<a name="L338" href="source/drivers/net/ethernet/smsc/smc91x.c#L338">338</a>         <a href="ident?i=SMC_WAIT_MMU_BUSY">SMC_WAIT_MMU_BUSY</a>(<a href="ident?i=lp">lp</a>);
<a name="L339" href="source/drivers/net/ethernet/smsc/smc91x.c#L339">339</a> }
<a name="L340" href="source/drivers/net/ethernet/smsc/smc91x.c#L340">340</a> 
<a name="L341" href="source/drivers/net/ethernet/smsc/smc91x.c#L341">341</a> <b><i>/*</i></b>
<a name="L342" href="source/drivers/net/ethernet/smsc/smc91x.c#L342">342</a> <b><i> * Enable Interrupts, Receive, and Transmit</i></b>
<a name="L343" href="source/drivers/net/ethernet/smsc/smc91x.c#L343">343</a> <b><i> */</i></b>
<a name="L344" href="source/drivers/net/ethernet/smsc/smc91x.c#L344">344</a> static void <a href="ident?i=smc_enable">smc_enable</a>(struct <a href="ident?i=net_device">net_device</a> *<a href="ident?i=dev">dev</a>)
<a name="L345" href="source/drivers/net/ethernet/smsc/smc91x.c#L345">345</a> {
<a name="L346" href="source/drivers/net/ethernet/smsc/smc91x.c#L346">346</a>         struct <a href="ident?i=smc_local">smc_local</a> *<a href="ident?i=lp">lp</a> = <a href="ident?i=netdev_priv">netdev_priv</a>(<a href="ident?i=dev">dev</a>);
<a name="L347" href="source/drivers/net/ethernet/smsc/smc91x.c#L347">347</a>         void <a href="ident?i=__iomem">__iomem</a> *<a href="ident?i=ioaddr">ioaddr</a> = <a href="ident?i=lp">lp</a>-&gt;<a href="ident?i=base">base</a>;
<a name="L348" href="source/drivers/net/ethernet/smsc/smc91x.c#L348">348</a>         int <a href="ident?i=mask">mask</a>;
<a name="L349" href="source/drivers/net/ethernet/smsc/smc91x.c#L349">349</a> 
<a name="L350" href="source/drivers/net/ethernet/smsc/smc91x.c#L350">350</a>         <a href="ident?i=DBG">DBG</a>(2, <a href="ident?i=dev">dev</a>, <i>"%s\n"</i>, <a href="ident?i=__func__">__func__</a>);
<a name="L351" href="source/drivers/net/ethernet/smsc/smc91x.c#L351">351</a> 
<a name="L352" href="source/drivers/net/ethernet/smsc/smc91x.c#L352">352</a>         <b><i>/* see the header file for options in TCR/RCR DEFAULT */</i></b>
<a name="L353" href="source/drivers/net/ethernet/smsc/smc91x.c#L353">353</a>         <a href="ident?i=SMC_SELECT_BANK">SMC_SELECT_BANK</a>(<a href="ident?i=lp">lp</a>, 0);
<a name="L354" href="source/drivers/net/ethernet/smsc/smc91x.c#L354">354</a>         <a href="ident?i=SMC_SET_TCR">SMC_SET_TCR</a>(<a href="ident?i=lp">lp</a>, <a href="ident?i=lp">lp</a>-&gt;tcr_cur_mode);
<a name="L355" href="source/drivers/net/ethernet/smsc/smc91x.c#L355">355</a>         <a href="ident?i=SMC_SET_RCR">SMC_SET_RCR</a>(<a href="ident?i=lp">lp</a>, <a href="ident?i=lp">lp</a>-&gt;rcr_cur_mode);
<a name="L356" href="source/drivers/net/ethernet/smsc/smc91x.c#L356">356</a> 
<a name="L357" href="source/drivers/net/ethernet/smsc/smc91x.c#L357">357</a>         <a href="ident?i=SMC_SELECT_BANK">SMC_SELECT_BANK</a>(<a href="ident?i=lp">lp</a>, 1);
<a name="L358" href="source/drivers/net/ethernet/smsc/smc91x.c#L358">358</a>         <a href="ident?i=SMC_SET_MAC_ADDR">SMC_SET_MAC_ADDR</a>(<a href="ident?i=lp">lp</a>, <a href="ident?i=dev">dev</a>-&gt;dev_addr);
<a name="L359" href="source/drivers/net/ethernet/smsc/smc91x.c#L359">359</a> 
<a name="L360" href="source/drivers/net/ethernet/smsc/smc91x.c#L360">360</a>         <b><i>/* now, enable interrupts */</i></b>
<a name="L361" href="source/drivers/net/ethernet/smsc/smc91x.c#L361">361</a>         <a href="ident?i=mask">mask</a> = <a href="ident?i=IM_EPH_INT">IM_EPH_INT</a>|<a href="ident?i=IM_RX_OVRN_INT">IM_RX_OVRN_INT</a>|<a href="ident?i=IM_RCV_INT">IM_RCV_INT</a>;
<a name="L362" href="source/drivers/net/ethernet/smsc/smc91x.c#L362">362</a>         if (<a href="ident?i=lp">lp</a>-&gt;<a href="ident?i=version">version</a> &gt;= (<a href="ident?i=CHIP_91100">CHIP_91100</a> &lt;&lt; 4))
<a name="L363" href="source/drivers/net/ethernet/smsc/smc91x.c#L363">363</a>                 <a href="ident?i=mask">mask</a> |= <a href="ident?i=IM_MDINT">IM_MDINT</a>;
<a name="L364" href="source/drivers/net/ethernet/smsc/smc91x.c#L364">364</a>         <a href="ident?i=SMC_SELECT_BANK">SMC_SELECT_BANK</a>(<a href="ident?i=lp">lp</a>, 2);
<a name="L365" href="source/drivers/net/ethernet/smsc/smc91x.c#L365">365</a>         <a href="ident?i=SMC_SET_INT_MASK">SMC_SET_INT_MASK</a>(<a href="ident?i=lp">lp</a>, <a href="ident?i=mask">mask</a>);
<a name="L366" href="source/drivers/net/ethernet/smsc/smc91x.c#L366">366</a> 
<a name="L367" href="source/drivers/net/ethernet/smsc/smc91x.c#L367">367</a>         <b><i>/*</i></b>
<a name="L368" href="source/drivers/net/ethernet/smsc/smc91x.c#L368">368</a> <b><i>         * From this point the register bank must _NOT_ be switched away</i></b>
<a name="L369" href="source/drivers/net/ethernet/smsc/smc91x.c#L369">369</a> <b><i>         * to something else than bank 2 without proper locking against</i></b>
<a name="L370" href="source/drivers/net/ethernet/smsc/smc91x.c#L370">370</a> <b><i>         * races with any tasklet or interrupt handlers until smc_shutdown()</i></b>
<a name="L371" href="source/drivers/net/ethernet/smsc/smc91x.c#L371">371</a> <b><i>         * or smc_reset() is called.</i></b>
<a name="L372" href="source/drivers/net/ethernet/smsc/smc91x.c#L372">372</a> <b><i>         */</i></b>
<a name="L373" href="source/drivers/net/ethernet/smsc/smc91x.c#L373">373</a> }
<a name="L374" href="source/drivers/net/ethernet/smsc/smc91x.c#L374">374</a> 
<a name="L375" href="source/drivers/net/ethernet/smsc/smc91x.c#L375">375</a> <b><i>/*</i></b>
<a name="L376" href="source/drivers/net/ethernet/smsc/smc91x.c#L376">376</a> <b><i> * this puts the device in an inactive state</i></b>
<a name="L377" href="source/drivers/net/ethernet/smsc/smc91x.c#L377">377</a> <b><i> */</i></b>
<a name="L378" href="source/drivers/net/ethernet/smsc/smc91x.c#L378">378</a> static void <a href="ident?i=smc_shutdown">smc_shutdown</a>(struct <a href="ident?i=net_device">net_device</a> *<a href="ident?i=dev">dev</a>)
<a name="L379" href="source/drivers/net/ethernet/smsc/smc91x.c#L379">379</a> {
<a name="L380" href="source/drivers/net/ethernet/smsc/smc91x.c#L380">380</a>         struct <a href="ident?i=smc_local">smc_local</a> *<a href="ident?i=lp">lp</a> = <a href="ident?i=netdev_priv">netdev_priv</a>(<a href="ident?i=dev">dev</a>);
<a name="L381" href="source/drivers/net/ethernet/smsc/smc91x.c#L381">381</a>         void <a href="ident?i=__iomem">__iomem</a> *<a href="ident?i=ioaddr">ioaddr</a> = <a href="ident?i=lp">lp</a>-&gt;<a href="ident?i=base">base</a>;
<a name="L382" href="source/drivers/net/ethernet/smsc/smc91x.c#L382">382</a>         struct <a href="ident?i=sk_buff">sk_buff</a> *pending_skb;
<a name="L383" href="source/drivers/net/ethernet/smsc/smc91x.c#L383">383</a> 
<a name="L384" href="source/drivers/net/ethernet/smsc/smc91x.c#L384">384</a>         <a href="ident?i=DBG">DBG</a>(2, <a href="ident?i=dev">dev</a>, <i>"%s: %s\n"</i>, <a href="ident?i=CARDNAME">CARDNAME</a>, <a href="ident?i=__func__">__func__</a>);
<a name="L385" href="source/drivers/net/ethernet/smsc/smc91x.c#L385">385</a> 
<a name="L386" href="source/drivers/net/ethernet/smsc/smc91x.c#L386">386</a>         <b><i>/* no more interrupts for me */</i></b>
<a name="L387" href="source/drivers/net/ethernet/smsc/smc91x.c#L387">387</a>         <a href="ident?i=spin_lock_irq">spin_lock_irq</a>(&amp;<a href="ident?i=lp">lp</a>-&gt;<a href="ident?i=lock">lock</a>);
<a name="L388" href="source/drivers/net/ethernet/smsc/smc91x.c#L388">388</a>         <a href="ident?i=SMC_SELECT_BANK">SMC_SELECT_BANK</a>(<a href="ident?i=lp">lp</a>, 2);
<a name="L389" href="source/drivers/net/ethernet/smsc/smc91x.c#L389">389</a>         <a href="ident?i=SMC_SET_INT_MASK">SMC_SET_INT_MASK</a>(<a href="ident?i=lp">lp</a>, 0);
<a name="L390" href="source/drivers/net/ethernet/smsc/smc91x.c#L390">390</a>         pending_skb = <a href="ident?i=lp">lp</a>-&gt;pending_tx_skb;
<a name="L391" href="source/drivers/net/ethernet/smsc/smc91x.c#L391">391</a>         <a href="ident?i=lp">lp</a>-&gt;pending_tx_skb = <a href="ident?i=NULL">NULL</a>;
<a name="L392" href="source/drivers/net/ethernet/smsc/smc91x.c#L392">392</a>         <a href="ident?i=spin_unlock_irq">spin_unlock_irq</a>(&amp;<a href="ident?i=lp">lp</a>-&gt;<a href="ident?i=lock">lock</a>);
<a name="L393" href="source/drivers/net/ethernet/smsc/smc91x.c#L393">393</a>         if (pending_skb)
<a name="L394" href="source/drivers/net/ethernet/smsc/smc91x.c#L394">394</a>                 <a href="ident?i=dev_kfree_skb">dev_kfree_skb</a>(pending_skb);
<a name="L395" href="source/drivers/net/ethernet/smsc/smc91x.c#L395">395</a> 
<a name="L396" href="source/drivers/net/ethernet/smsc/smc91x.c#L396">396</a>         <b><i>/* and tell the card to stay away from that nasty outside world */</i></b>
<a name="L397" href="source/drivers/net/ethernet/smsc/smc91x.c#L397">397</a>         <a href="ident?i=SMC_SELECT_BANK">SMC_SELECT_BANK</a>(<a href="ident?i=lp">lp</a>, 0);
<a name="L398" href="source/drivers/net/ethernet/smsc/smc91x.c#L398">398</a>         <a href="ident?i=SMC_SET_RCR">SMC_SET_RCR</a>(<a href="ident?i=lp">lp</a>, <a href="ident?i=RCR_CLEAR">RCR_CLEAR</a>);
<a name="L399" href="source/drivers/net/ethernet/smsc/smc91x.c#L399">399</a>         <a href="ident?i=SMC_SET_TCR">SMC_SET_TCR</a>(<a href="ident?i=lp">lp</a>, <a href="ident?i=TCR_CLEAR">TCR_CLEAR</a>);
<a name="L400" href="source/drivers/net/ethernet/smsc/smc91x.c#L400">400</a> 
<a name="L401" href="source/drivers/net/ethernet/smsc/smc91x.c#L401">401</a> #ifdef <a href="ident?i=POWER_DOWN">POWER_DOWN</a>
<a name="L402" href="source/drivers/net/ethernet/smsc/smc91x.c#L402">402</a>         <b><i>/* finally, shut the chip down */</i></b>
<a name="L403" href="source/drivers/net/ethernet/smsc/smc91x.c#L403">403</a>         <a href="ident?i=SMC_SELECT_BANK">SMC_SELECT_BANK</a>(<a href="ident?i=lp">lp</a>, 1);
<a name="L404" href="source/drivers/net/ethernet/smsc/smc91x.c#L404">404</a>         <a href="ident?i=SMC_SET_CONFIG">SMC_SET_CONFIG</a>(<a href="ident?i=lp">lp</a>, <a href="ident?i=SMC_GET_CONFIG">SMC_GET_CONFIG</a>(<a href="ident?i=lp">lp</a>) &amp; ~CONFIG_EPH_POWER_EN);
<a name="L405" href="source/drivers/net/ethernet/smsc/smc91x.c#L405">405</a> #endif
<a name="L406" href="source/drivers/net/ethernet/smsc/smc91x.c#L406">406</a> }
<a name="L407" href="source/drivers/net/ethernet/smsc/smc91x.c#L407">407</a> 
<a name="L408" href="source/drivers/net/ethernet/smsc/smc91x.c#L408">408</a> <b><i>/*</i></b>
<a name="L409" href="source/drivers/net/ethernet/smsc/smc91x.c#L409">409</a> <b><i> * This is the procedure to handle the receipt of a packet.</i></b>
<a name="L410" href="source/drivers/net/ethernet/smsc/smc91x.c#L410">410</a> <b><i> */</i></b>
<a name="L411" href="source/drivers/net/ethernet/smsc/smc91x.c#L411">411</a> static inline void  <a href="ident?i=smc_rcv">smc_rcv</a>(struct <a href="ident?i=net_device">net_device</a> *<a href="ident?i=dev">dev</a>)
<a name="L412" href="source/drivers/net/ethernet/smsc/smc91x.c#L412">412</a> {
<a name="L413" href="source/drivers/net/ethernet/smsc/smc91x.c#L413">413</a>         struct <a href="ident?i=smc_local">smc_local</a> *<a href="ident?i=lp">lp</a> = <a href="ident?i=netdev_priv">netdev_priv</a>(<a href="ident?i=dev">dev</a>);
<a name="L414" href="source/drivers/net/ethernet/smsc/smc91x.c#L414">414</a>         void <a href="ident?i=__iomem">__iomem</a> *<a href="ident?i=ioaddr">ioaddr</a> = <a href="ident?i=lp">lp</a>-&gt;<a href="ident?i=base">base</a>;
<a name="L415" href="source/drivers/net/ethernet/smsc/smc91x.c#L415">415</a>         unsigned int packet_number, <a href="ident?i=status">status</a>, packet_len;
<a name="L416" href="source/drivers/net/ethernet/smsc/smc91x.c#L416">416</a> 
<a name="L417" href="source/drivers/net/ethernet/smsc/smc91x.c#L417">417</a>         <a href="ident?i=DBG">DBG</a>(3, <a href="ident?i=dev">dev</a>, <i>"%s\n"</i>, <a href="ident?i=__func__">__func__</a>);
<a name="L418" href="source/drivers/net/ethernet/smsc/smc91x.c#L418">418</a> 
<a name="L419" href="source/drivers/net/ethernet/smsc/smc91x.c#L419">419</a>         packet_number = <a href="ident?i=SMC_GET_RXFIFO">SMC_GET_RXFIFO</a>(<a href="ident?i=lp">lp</a>);
<a name="L420" href="source/drivers/net/ethernet/smsc/smc91x.c#L420">420</a>         if (<a href="ident?i=unlikely">unlikely</a>(packet_number &amp; <a href="ident?i=RXFIFO_REMPTY">RXFIFO_REMPTY</a>)) {
<a name="L421" href="source/drivers/net/ethernet/smsc/smc91x.c#L421">421</a>                 <a href="ident?i=PRINTK">PRINTK</a>(<a href="ident?i=dev">dev</a>, <i>"smc_rcv with nothing on FIFO.\n"</i>);
<a name="L422" href="source/drivers/net/ethernet/smsc/smc91x.c#L422">422</a>                 return;
<a name="L423" href="source/drivers/net/ethernet/smsc/smc91x.c#L423">423</a>         }
<a name="L424" href="source/drivers/net/ethernet/smsc/smc91x.c#L424">424</a> 
<a name="L425" href="source/drivers/net/ethernet/smsc/smc91x.c#L425">425</a>         <b><i>/* read from start of packet */</i></b>
<a name="L426" href="source/drivers/net/ethernet/smsc/smc91x.c#L426">426</a>         <a href="ident?i=SMC_SET_PTR">SMC_SET_PTR</a>(<a href="ident?i=lp">lp</a>, <a href="ident?i=PTR_READ">PTR_READ</a> | <a href="ident?i=PTR_RCV">PTR_RCV</a> | <a href="ident?i=PTR_AUTOINC">PTR_AUTOINC</a>);
<a name="L427" href="source/drivers/net/ethernet/smsc/smc91x.c#L427">427</a> 
<a name="L428" href="source/drivers/net/ethernet/smsc/smc91x.c#L428">428</a>         <b><i>/* First two words are status and packet length */</i></b>
<a name="L429" href="source/drivers/net/ethernet/smsc/smc91x.c#L429">429</a>         <a href="ident?i=SMC_GET_PKT_HDR">SMC_GET_PKT_HDR</a>(<a href="ident?i=lp">lp</a>, <a href="ident?i=status">status</a>, packet_len);
<a name="L430" href="source/drivers/net/ethernet/smsc/smc91x.c#L430">430</a>         packet_len &amp;= 0x07ff;  <b><i>/* mask off top bits */</i></b>
<a name="L431" href="source/drivers/net/ethernet/smsc/smc91x.c#L431">431</a>         <a href="ident?i=DBG">DBG</a>(2, <a href="ident?i=dev">dev</a>, <i>"RX PNR 0x%x STATUS 0x%04x LENGTH 0x%04x (%d)\n"</i>,
<a name="L432" href="source/drivers/net/ethernet/smsc/smc91x.c#L432">432</a>             packet_number, <a href="ident?i=status">status</a>, packet_len, packet_len);
<a name="L433" href="source/drivers/net/ethernet/smsc/smc91x.c#L433">433</a> 
<a name="L434" href="source/drivers/net/ethernet/smsc/smc91x.c#L434">434</a>         back:
<a name="L435" href="source/drivers/net/ethernet/smsc/smc91x.c#L435">435</a>         if (<a href="ident?i=unlikely">unlikely</a>(packet_len &lt; 6 || <a href="ident?i=status">status</a> &amp; <a href="ident?i=RS_ERRORS">RS_ERRORS</a>)) {
<a name="L436" href="source/drivers/net/ethernet/smsc/smc91x.c#L436">436</a>                 if (<a href="ident?i=status">status</a> &amp; <a href="ident?i=RS_TOOLONG">RS_TOOLONG</a> &amp;&amp; packet_len &lt;= (1514 + 4 + 6)) {
<a name="L437" href="source/drivers/net/ethernet/smsc/smc91x.c#L437">437</a>                         <b><i>/* accept VLAN packets */</i></b>
<a name="L438" href="source/drivers/net/ethernet/smsc/smc91x.c#L438">438</a>                         <a href="ident?i=status">status</a> &amp;= ~RS_TOOLONG;
<a name="L439" href="source/drivers/net/ethernet/smsc/smc91x.c#L439">439</a>                         goto back;
<a name="L440" href="source/drivers/net/ethernet/smsc/smc91x.c#L440">440</a>                 }
<a name="L441" href="source/drivers/net/ethernet/smsc/smc91x.c#L441">441</a>                 if (packet_len &lt; 6) {
<a name="L442" href="source/drivers/net/ethernet/smsc/smc91x.c#L442">442</a>                         <b><i>/* bloody hardware */</i></b>
<a name="L443" href="source/drivers/net/ethernet/smsc/smc91x.c#L443">443</a>                         <a href="ident?i=netdev_err">netdev_err</a>(<a href="ident?i=dev">dev</a>, <i>"fubar (rxlen %u status %x\n"</i>,
<a name="L444" href="source/drivers/net/ethernet/smsc/smc91x.c#L444">444</a>                                    packet_len, <a href="ident?i=status">status</a>);
<a name="L445" href="source/drivers/net/ethernet/smsc/smc91x.c#L445">445</a>                         <a href="ident?i=status">status</a> |= <a href="ident?i=RS_TOOSHORT">RS_TOOSHORT</a>;
<a name="L446" href="source/drivers/net/ethernet/smsc/smc91x.c#L446">446</a>                 }
<a name="L447" href="source/drivers/net/ethernet/smsc/smc91x.c#L447">447</a>                 <a href="ident?i=SMC_WAIT_MMU_BUSY">SMC_WAIT_MMU_BUSY</a>(<a href="ident?i=lp">lp</a>);
<a name="L448" href="source/drivers/net/ethernet/smsc/smc91x.c#L448">448</a>                 <a href="ident?i=SMC_SET_MMU_CMD">SMC_SET_MMU_CMD</a>(<a href="ident?i=lp">lp</a>, <a href="ident?i=MC_RELEASE">MC_RELEASE</a>);
<a name="L449" href="source/drivers/net/ethernet/smsc/smc91x.c#L449">449</a>                 <a href="ident?i=dev">dev</a>-&gt;<a href="ident?i=stats">stats</a>.rx_errors++;
<a name="L450" href="source/drivers/net/ethernet/smsc/smc91x.c#L450">450</a>                 if (<a href="ident?i=status">status</a> &amp; <a href="ident?i=RS_ALGNERR">RS_ALGNERR</a>)
<a name="L451" href="source/drivers/net/ethernet/smsc/smc91x.c#L451">451</a>                         <a href="ident?i=dev">dev</a>-&gt;<a href="ident?i=stats">stats</a>.rx_frame_errors++;
<a name="L452" href="source/drivers/net/ethernet/smsc/smc91x.c#L452">452</a>                 if (<a href="ident?i=status">status</a> &amp; (<a href="ident?i=RS_TOOSHORT">RS_TOOSHORT</a> | <a href="ident?i=RS_TOOLONG">RS_TOOLONG</a>))
<a name="L453" href="source/drivers/net/ethernet/smsc/smc91x.c#L453">453</a>                         <a href="ident?i=dev">dev</a>-&gt;<a href="ident?i=stats">stats</a>.rx_length_errors++;
<a name="L454" href="source/drivers/net/ethernet/smsc/smc91x.c#L454">454</a>                 if (<a href="ident?i=status">status</a> &amp; <a href="ident?i=RS_BADCRC">RS_BADCRC</a>)
<a name="L455" href="source/drivers/net/ethernet/smsc/smc91x.c#L455">455</a>                         <a href="ident?i=dev">dev</a>-&gt;<a href="ident?i=stats">stats</a>.rx_crc_errors++;
<a name="L456" href="source/drivers/net/ethernet/smsc/smc91x.c#L456">456</a>         } else {
<a name="L457" href="source/drivers/net/ethernet/smsc/smc91x.c#L457">457</a>                 struct <a href="ident?i=sk_buff">sk_buff</a> *<a href="ident?i=skb">skb</a>;
<a name="L458" href="source/drivers/net/ethernet/smsc/smc91x.c#L458">458</a>                 unsigned char *<a href="ident?i=data">data</a>;
<a name="L459" href="source/drivers/net/ethernet/smsc/smc91x.c#L459">459</a>                 unsigned int <a href="ident?i=data_len">data_len</a>;
<a name="L460" href="source/drivers/net/ethernet/smsc/smc91x.c#L460">460</a> 
<a name="L461" href="source/drivers/net/ethernet/smsc/smc91x.c#L461">461</a>                 <b><i>/* set multicast stats */</i></b>
<a name="L462" href="source/drivers/net/ethernet/smsc/smc91x.c#L462">462</a>                 if (<a href="ident?i=status">status</a> &amp; <a href="ident?i=RS_MULTICAST">RS_MULTICAST</a>)
<a name="L463" href="source/drivers/net/ethernet/smsc/smc91x.c#L463">463</a>                         <a href="ident?i=dev">dev</a>-&gt;<a href="ident?i=stats">stats</a>.multicast++;
<a name="L464" href="source/drivers/net/ethernet/smsc/smc91x.c#L464">464</a> 
<a name="L465" href="source/drivers/net/ethernet/smsc/smc91x.c#L465">465</a>                 <b><i>/*</i></b>
<a name="L466" href="source/drivers/net/ethernet/smsc/smc91x.c#L466">466</a> <b><i>                 * Actual payload is packet_len - 6 (or 5 if odd byte).</i></b>
<a name="L467" href="source/drivers/net/ethernet/smsc/smc91x.c#L467">467</a> <b><i>                 * We want skb_reserve(2) and the final ctrl word</i></b>
<a name="L468" href="source/drivers/net/ethernet/smsc/smc91x.c#L468">468</a> <b><i>                 * (2 bytes, possibly containing the payload odd byte).</i></b>
<a name="L469" href="source/drivers/net/ethernet/smsc/smc91x.c#L469">469</a> <b><i>                 * Furthermore, we add 2 bytes to allow rounding up to</i></b>
<a name="L470" href="source/drivers/net/ethernet/smsc/smc91x.c#L470">470</a> <b><i>                 * multiple of 4 bytes on 32 bit buses.</i></b>
<a name="L471" href="source/drivers/net/ethernet/smsc/smc91x.c#L471">471</a> <b><i>                 * Hence packet_len - 6 + 2 + 2 + 2.</i></b>
<a name="L472" href="source/drivers/net/ethernet/smsc/smc91x.c#L472">472</a> <b><i>                 */</i></b>
<a name="L473" href="source/drivers/net/ethernet/smsc/smc91x.c#L473">473</a>                 <a href="ident?i=skb">skb</a> = <a href="ident?i=netdev_alloc_skb">netdev_alloc_skb</a>(<a href="ident?i=dev">dev</a>, packet_len);
<a name="L474" href="source/drivers/net/ethernet/smsc/smc91x.c#L474">474</a>                 if (<a href="ident?i=unlikely">unlikely</a>(<a href="ident?i=skb">skb</a> == <a href="ident?i=NULL">NULL</a>)) {
<a name="L475" href="source/drivers/net/ethernet/smsc/smc91x.c#L475">475</a>                         <a href="ident?i=SMC_WAIT_MMU_BUSY">SMC_WAIT_MMU_BUSY</a>(<a href="ident?i=lp">lp</a>);
<a name="L476" href="source/drivers/net/ethernet/smsc/smc91x.c#L476">476</a>                         <a href="ident?i=SMC_SET_MMU_CMD">SMC_SET_MMU_CMD</a>(<a href="ident?i=lp">lp</a>, <a href="ident?i=MC_RELEASE">MC_RELEASE</a>);
<a name="L477" href="source/drivers/net/ethernet/smsc/smc91x.c#L477">477</a>                         <a href="ident?i=dev">dev</a>-&gt;<a href="ident?i=stats">stats</a>.rx_dropped++;
<a name="L478" href="source/drivers/net/ethernet/smsc/smc91x.c#L478">478</a>                         return;
<a name="L479" href="source/drivers/net/ethernet/smsc/smc91x.c#L479">479</a>                 }
<a name="L480" href="source/drivers/net/ethernet/smsc/smc91x.c#L480">480</a> 
<a name="L481" href="source/drivers/net/ethernet/smsc/smc91x.c#L481">481</a>                 <b><i>/* Align IP header to 32 bits */</i></b>
<a name="L482" href="source/drivers/net/ethernet/smsc/smc91x.c#L482">482</a>                 <a href="ident?i=skb_reserve">skb_reserve</a>(<a href="ident?i=skb">skb</a>, 2);
<a name="L483" href="source/drivers/net/ethernet/smsc/smc91x.c#L483">483</a> 
<a name="L484" href="source/drivers/net/ethernet/smsc/smc91x.c#L484">484</a>                 <b><i>/* BUG: the LAN91C111 rev A never sets this bit. Force it. */</i></b>
<a name="L485" href="source/drivers/net/ethernet/smsc/smc91x.c#L485">485</a>                 if (<a href="ident?i=lp">lp</a>-&gt;<a href="ident?i=version">version</a> == 0x90)
<a name="L486" href="source/drivers/net/ethernet/smsc/smc91x.c#L486">486</a>                         <a href="ident?i=status">status</a> |= <a href="ident?i=RS_ODDFRAME">RS_ODDFRAME</a>;
<a name="L487" href="source/drivers/net/ethernet/smsc/smc91x.c#L487">487</a> 
<a name="L488" href="source/drivers/net/ethernet/smsc/smc91x.c#L488">488</a>                 <b><i>/*</i></b>
<a name="L489" href="source/drivers/net/ethernet/smsc/smc91x.c#L489">489</a> <b><i>                 * If odd length: packet_len - 5,</i></b>
<a name="L490" href="source/drivers/net/ethernet/smsc/smc91x.c#L490">490</a> <b><i>                 * otherwise packet_len - 6.</i></b>
<a name="L491" href="source/drivers/net/ethernet/smsc/smc91x.c#L491">491</a> <b><i>                 * With the trailing ctrl byte it's packet_len - 4.</i></b>
<a name="L492" href="source/drivers/net/ethernet/smsc/smc91x.c#L492">492</a> <b><i>                 */</i></b>
<a name="L493" href="source/drivers/net/ethernet/smsc/smc91x.c#L493">493</a>                 <a href="ident?i=data_len">data_len</a> = packet_len - ((<a href="ident?i=status">status</a> &amp; <a href="ident?i=RS_ODDFRAME">RS_ODDFRAME</a>) ? 5 : 6);
<a name="L494" href="source/drivers/net/ethernet/smsc/smc91x.c#L494">494</a>                 <a href="ident?i=data">data</a> = <a href="ident?i=skb_put">skb_put</a>(<a href="ident?i=skb">skb</a>, <a href="ident?i=data_len">data_len</a>);
<a name="L495" href="source/drivers/net/ethernet/smsc/smc91x.c#L495">495</a>                 <a href="ident?i=SMC_PULL_DATA">SMC_PULL_DATA</a>(<a href="ident?i=lp">lp</a>, <a href="ident?i=data">data</a>, packet_len - 4);
<a name="L496" href="source/drivers/net/ethernet/smsc/smc91x.c#L496">496</a> 
<a name="L497" href="source/drivers/net/ethernet/smsc/smc91x.c#L497">497</a>                 <a href="ident?i=SMC_WAIT_MMU_BUSY">SMC_WAIT_MMU_BUSY</a>(<a href="ident?i=lp">lp</a>);
<a name="L498" href="source/drivers/net/ethernet/smsc/smc91x.c#L498">498</a>                 <a href="ident?i=SMC_SET_MMU_CMD">SMC_SET_MMU_CMD</a>(<a href="ident?i=lp">lp</a>, <a href="ident?i=MC_RELEASE">MC_RELEASE</a>);
<a name="L499" href="source/drivers/net/ethernet/smsc/smc91x.c#L499">499</a> 
<a name="L500" href="source/drivers/net/ethernet/smsc/smc91x.c#L500">500</a>                 <a href="ident?i=PRINT_PKT">PRINT_PKT</a>(<a href="ident?i=data">data</a>, packet_len - 4);
<a name="L501" href="source/drivers/net/ethernet/smsc/smc91x.c#L501">501</a> 
<a name="L502" href="source/drivers/net/ethernet/smsc/smc91x.c#L502">502</a>                 <a href="ident?i=skb">skb</a>-&gt;<a href="ident?i=protocol">protocol</a> = <a href="ident?i=eth_type_trans">eth_type_trans</a>(<a href="ident?i=skb">skb</a>, <a href="ident?i=dev">dev</a>);
<a name="L503" href="source/drivers/net/ethernet/smsc/smc91x.c#L503">503</a>                 <a href="ident?i=netif_rx">netif_rx</a>(<a href="ident?i=skb">skb</a>);
<a name="L504" href="source/drivers/net/ethernet/smsc/smc91x.c#L504">504</a>                 <a href="ident?i=dev">dev</a>-&gt;<a href="ident?i=stats">stats</a>.rx_packets++;
<a name="L505" href="source/drivers/net/ethernet/smsc/smc91x.c#L505">505</a>                 <a href="ident?i=dev">dev</a>-&gt;<a href="ident?i=stats">stats</a>.<a href="ident?i=rx_bytes">rx_bytes</a> += <a href="ident?i=data_len">data_len</a>;
<a name="L506" href="source/drivers/net/ethernet/smsc/smc91x.c#L506">506</a>         }
<a name="L507" href="source/drivers/net/ethernet/smsc/smc91x.c#L507">507</a> }
<a name="L508" href="source/drivers/net/ethernet/smsc/smc91x.c#L508">508</a> 
<a name="L509" href="source/drivers/net/ethernet/smsc/smc91x.c#L509">509</a> #ifdef <a href="ident?i=CONFIG_SMP">CONFIG_SMP</a>
<a name="L510" href="source/drivers/net/ethernet/smsc/smc91x.c#L510">510</a> <b><i>/*</i></b>
<a name="L511" href="source/drivers/net/ethernet/smsc/smc91x.c#L511">511</a> <b><i> * On SMP we have the following problem:</i></b>
<a name="L512" href="source/drivers/net/ethernet/smsc/smc91x.c#L512">512</a> <b><i> *</i></b>
<a name="L513" href="source/drivers/net/ethernet/smsc/smc91x.c#L513">513</a> <b><i> *      A = smc_hardware_send_pkt()</i></b>
<a name="L514" href="source/drivers/net/ethernet/smsc/smc91x.c#L514">514</a> <b><i> *      B = smc_hard_start_xmit()</i></b>
<a name="L515" href="source/drivers/net/ethernet/smsc/smc91x.c#L515">515</a> <b><i> *      C = smc_interrupt()</i></b>
<a name="L516" href="source/drivers/net/ethernet/smsc/smc91x.c#L516">516</a> <b><i> *</i></b>
<a name="L517" href="source/drivers/net/ethernet/smsc/smc91x.c#L517">517</a> <b><i> * A and B can never be executed simultaneously.  However, at least on UP,</i></b>
<a name="L518" href="source/drivers/net/ethernet/smsc/smc91x.c#L518">518</a> <b><i> * it is possible (and even desirable) for C to interrupt execution of</i></b>
<a name="L519" href="source/drivers/net/ethernet/smsc/smc91x.c#L519">519</a> <b><i> * A or B in order to have better RX reliability and avoid overruns.</i></b>
<a name="L520" href="source/drivers/net/ethernet/smsc/smc91x.c#L520">520</a> <b><i> * C, just like A and B, must have exclusive access to the chip and</i></b>
<a name="L521" href="source/drivers/net/ethernet/smsc/smc91x.c#L521">521</a> <b><i> * each of them must lock against any other concurrent access.</i></b>
<a name="L522" href="source/drivers/net/ethernet/smsc/smc91x.c#L522">522</a> <b><i> * Unfortunately this is not possible to have C suspend execution of A or</i></b>
<a name="L523" href="source/drivers/net/ethernet/smsc/smc91x.c#L523">523</a> <b><i> * B taking place on another CPU. On UP this is no an issue since A and B</i></b>
<a name="L524" href="source/drivers/net/ethernet/smsc/smc91x.c#L524">524</a> <b><i> * are run from softirq context and C from hard IRQ context, and there is</i></b>
<a name="L525" href="source/drivers/net/ethernet/smsc/smc91x.c#L525">525</a> <b><i> * no other CPU where concurrent access can happen.</i></b>
<a name="L526" href="source/drivers/net/ethernet/smsc/smc91x.c#L526">526</a> <b><i> * If ever there is a way to force at least B and C to always be executed</i></b>
<a name="L527" href="source/drivers/net/ethernet/smsc/smc91x.c#L527">527</a> <b><i> * on the same CPU then we could use read/write locks to protect against</i></b>
<a name="L528" href="source/drivers/net/ethernet/smsc/smc91x.c#L528">528</a> <b><i> * any other concurrent access and C would always interrupt B. But life</i></b>
<a name="L529" href="source/drivers/net/ethernet/smsc/smc91x.c#L529">529</a> <b><i> * isn't that easy in a SMP world...</i></b>
<a name="L530" href="source/drivers/net/ethernet/smsc/smc91x.c#L530">530</a> <b><i> */</i></b>
<a name="L531" href="source/drivers/net/ethernet/smsc/smc91x.c#L531">531</a> #define <a href="ident?i=smc_special_trylock">smc_special_trylock</a>(<a href="ident?i=lock">lock</a>, <a href="ident?i=flags">flags</a>)                                \
<a name="L532" href="source/drivers/net/ethernet/smsc/smc91x.c#L532">532</a> ({                                                                      \
<a name="L533" href="source/drivers/net/ethernet/smsc/smc91x.c#L533">533</a>         int __ret;                                                      \
<a name="L534" href="source/drivers/net/ethernet/smsc/smc91x.c#L534">534</a>         <a href="ident?i=local_irq_save">local_irq_save</a>(<a href="ident?i=flags">flags</a>);                                          \
<a name="L535" href="source/drivers/net/ethernet/smsc/smc91x.c#L535">535</a>         __ret = <a href="ident?i=spin_trylock">spin_trylock</a>(<a href="ident?i=lock">lock</a>);                                     \
<a name="L536" href="source/drivers/net/ethernet/smsc/smc91x.c#L536">536</a>         if (!__ret)                                                     \
<a name="L537" href="source/drivers/net/ethernet/smsc/smc91x.c#L537">537</a>                 <a href="ident?i=local_irq_restore">local_irq_restore</a>(<a href="ident?i=flags">flags</a>);                               \
<a name="L538" href="source/drivers/net/ethernet/smsc/smc91x.c#L538">538</a>         __ret;                                                          \
<a name="L539" href="source/drivers/net/ethernet/smsc/smc91x.c#L539">539</a> })
<a name="L540" href="source/drivers/net/ethernet/smsc/smc91x.c#L540">540</a> #define <a href="ident?i=smc_special_lock">smc_special_lock</a>(<a href="ident?i=lock">lock</a>, <a href="ident?i=flags">flags</a>)           <a href="ident?i=spin_lock_irqsave">spin_lock_irqsave</a>(<a href="ident?i=lock">lock</a>, <a href="ident?i=flags">flags</a>)
<a name="L541" href="source/drivers/net/ethernet/smsc/smc91x.c#L541">541</a> #define <a href="ident?i=smc_special_unlock">smc_special_unlock</a>(<a href="ident?i=lock">lock</a>, <a href="ident?i=flags">flags</a>)         <a href="ident?i=spin_unlock_irqrestore">spin_unlock_irqrestore</a>(<a href="ident?i=lock">lock</a>, <a href="ident?i=flags">flags</a>)
<a name="L542" href="source/drivers/net/ethernet/smsc/smc91x.c#L542">542</a> #else
<a name="L543" href="source/drivers/net/ethernet/smsc/smc91x.c#L543">543</a> #define <a href="ident?i=smc_special_trylock">smc_special_trylock</a>(<a href="ident?i=lock">lock</a>, <a href="ident?i=flags">flags</a>)        ((void)<a href="ident?i=flags">flags</a>, <a href="ident?i=true">true</a>)
<a name="L544" href="source/drivers/net/ethernet/smsc/smc91x.c#L544">544</a> #define <a href="ident?i=smc_special_lock">smc_special_lock</a>(<a href="ident?i=lock">lock</a>, <a href="ident?i=flags">flags</a>)           do { <a href="ident?i=flags">flags</a> = 0; } while (0)
<a name="L545" href="source/drivers/net/ethernet/smsc/smc91x.c#L545">545</a> #define <a href="ident?i=smc_special_unlock">smc_special_unlock</a>(<a href="ident?i=lock">lock</a>, <a href="ident?i=flags">flags</a>) do { <a href="ident?i=flags">flags</a> = 0; } while (0)
<a name="L546" href="source/drivers/net/ethernet/smsc/smc91x.c#L546">546</a> #endif
<a name="L547" href="source/drivers/net/ethernet/smsc/smc91x.c#L547">547</a> 
<a name="L548" href="source/drivers/net/ethernet/smsc/smc91x.c#L548">548</a> <b><i>/*</i></b>
<a name="L549" href="source/drivers/net/ethernet/smsc/smc91x.c#L549">549</a> <b><i> * This is called to actually send a packet to the chip.</i></b>
<a name="L550" href="source/drivers/net/ethernet/smsc/smc91x.c#L550">550</a> <b><i> */</i></b>
<a name="L551" href="source/drivers/net/ethernet/smsc/smc91x.c#L551">551</a> static void <a href="ident?i=smc_hardware_send_pkt">smc_hardware_send_pkt</a>(unsigned long <a href="ident?i=data">data</a>)
<a name="L552" href="source/drivers/net/ethernet/smsc/smc91x.c#L552">552</a> {
<a name="L553" href="source/drivers/net/ethernet/smsc/smc91x.c#L553">553</a>         struct <a href="ident?i=net_device">net_device</a> *<a href="ident?i=dev">dev</a> = (struct <a href="ident?i=net_device">net_device</a> *)<a href="ident?i=data">data</a>;
<a name="L554" href="source/drivers/net/ethernet/smsc/smc91x.c#L554">554</a>         struct <a href="ident?i=smc_local">smc_local</a> *<a href="ident?i=lp">lp</a> = <a href="ident?i=netdev_priv">netdev_priv</a>(<a href="ident?i=dev">dev</a>);
<a name="L555" href="source/drivers/net/ethernet/smsc/smc91x.c#L555">555</a>         void <a href="ident?i=__iomem">__iomem</a> *<a href="ident?i=ioaddr">ioaddr</a> = <a href="ident?i=lp">lp</a>-&gt;<a href="ident?i=base">base</a>;
<a name="L556" href="source/drivers/net/ethernet/smsc/smc91x.c#L556">556</a>         struct <a href="ident?i=sk_buff">sk_buff</a> *<a href="ident?i=skb">skb</a>;
<a name="L557" href="source/drivers/net/ethernet/smsc/smc91x.c#L557">557</a>         unsigned int packet_no, <a href="ident?i=len">len</a>;
<a name="L558" href="source/drivers/net/ethernet/smsc/smc91x.c#L558">558</a>         unsigned char *<a href="ident?i=buf">buf</a>;
<a name="L559" href="source/drivers/net/ethernet/smsc/smc91x.c#L559">559</a>         unsigned long <a href="ident?i=flags">flags</a>;
<a name="L560" href="source/drivers/net/ethernet/smsc/smc91x.c#L560">560</a> 
<a name="L561" href="source/drivers/net/ethernet/smsc/smc91x.c#L561">561</a>         <a href="ident?i=DBG">DBG</a>(3, <a href="ident?i=dev">dev</a>, <i>"%s\n"</i>, <a href="ident?i=__func__">__func__</a>);
<a name="L562" href="source/drivers/net/ethernet/smsc/smc91x.c#L562">562</a> 
<a name="L563" href="source/drivers/net/ethernet/smsc/smc91x.c#L563">563</a>         if (!<a href="ident?i=smc_special_trylock">smc_special_trylock</a>(&amp;<a href="ident?i=lp">lp</a>-&gt;<a href="ident?i=lock">lock</a>, <a href="ident?i=flags">flags</a>)) {
<a name="L564" href="source/drivers/net/ethernet/smsc/smc91x.c#L564">564</a>                 <a href="ident?i=netif_stop_queue">netif_stop_queue</a>(<a href="ident?i=dev">dev</a>);
<a name="L565" href="source/drivers/net/ethernet/smsc/smc91x.c#L565">565</a>                 <a href="ident?i=tasklet_schedule">tasklet_schedule</a>(&amp;<a href="ident?i=lp">lp</a>-&gt;tx_task);
<a name="L566" href="source/drivers/net/ethernet/smsc/smc91x.c#L566">566</a>                 return;
<a name="L567" href="source/drivers/net/ethernet/smsc/smc91x.c#L567">567</a>         }
<a name="L568" href="source/drivers/net/ethernet/smsc/smc91x.c#L568">568</a> 
<a name="L569" href="source/drivers/net/ethernet/smsc/smc91x.c#L569">569</a>         <a href="ident?i=skb">skb</a> = <a href="ident?i=lp">lp</a>-&gt;pending_tx_skb;
<a name="L570" href="source/drivers/net/ethernet/smsc/smc91x.c#L570">570</a>         if (<a href="ident?i=unlikely">unlikely</a>(!<a href="ident?i=skb">skb</a>)) {
<a name="L571" href="source/drivers/net/ethernet/smsc/smc91x.c#L571">571</a>                 <a href="ident?i=smc_special_unlock">smc_special_unlock</a>(&amp;<a href="ident?i=lp">lp</a>-&gt;<a href="ident?i=lock">lock</a>, <a href="ident?i=flags">flags</a>);
<a name="L572" href="source/drivers/net/ethernet/smsc/smc91x.c#L572">572</a>                 return;
<a name="L573" href="source/drivers/net/ethernet/smsc/smc91x.c#L573">573</a>         }
<a name="L574" href="source/drivers/net/ethernet/smsc/smc91x.c#L574">574</a>         <a href="ident?i=lp">lp</a>-&gt;pending_tx_skb = <a href="ident?i=NULL">NULL</a>;
<a name="L575" href="source/drivers/net/ethernet/smsc/smc91x.c#L575">575</a> 
<a name="L576" href="source/drivers/net/ethernet/smsc/smc91x.c#L576">576</a>         packet_no = <a href="ident?i=SMC_GET_AR">SMC_GET_AR</a>(<a href="ident?i=lp">lp</a>);
<a name="L577" href="source/drivers/net/ethernet/smsc/smc91x.c#L577">577</a>         if (<a href="ident?i=unlikely">unlikely</a>(packet_no &amp; <a href="ident?i=AR_FAILED">AR_FAILED</a>)) {
<a name="L578" href="source/drivers/net/ethernet/smsc/smc91x.c#L578">578</a>                 <a href="ident?i=netdev_err">netdev_err</a>(<a href="ident?i=dev">dev</a>, <i>"Memory allocation failed.\n"</i>);
<a name="L579" href="source/drivers/net/ethernet/smsc/smc91x.c#L579">579</a>                 <a href="ident?i=dev">dev</a>-&gt;<a href="ident?i=stats">stats</a>.tx_errors++;
<a name="L580" href="source/drivers/net/ethernet/smsc/smc91x.c#L580">580</a>                 <a href="ident?i=dev">dev</a>-&gt;<a href="ident?i=stats">stats</a>.tx_fifo_errors++;
<a name="L581" href="source/drivers/net/ethernet/smsc/smc91x.c#L581">581</a>                 <a href="ident?i=smc_special_unlock">smc_special_unlock</a>(&amp;<a href="ident?i=lp">lp</a>-&gt;<a href="ident?i=lock">lock</a>, <a href="ident?i=flags">flags</a>);
<a name="L582" href="source/drivers/net/ethernet/smsc/smc91x.c#L582">582</a>                 goto <a href="ident?i=done">done</a>;
<a name="L583" href="source/drivers/net/ethernet/smsc/smc91x.c#L583">583</a>         }
<a name="L584" href="source/drivers/net/ethernet/smsc/smc91x.c#L584">584</a> 
<a name="L585" href="source/drivers/net/ethernet/smsc/smc91x.c#L585">585</a>         <b><i>/* point to the beginning of the packet */</i></b>
<a name="L586" href="source/drivers/net/ethernet/smsc/smc91x.c#L586">586</a>         <a href="ident?i=SMC_SET_PN">SMC_SET_PN</a>(<a href="ident?i=lp">lp</a>, packet_no);
<a name="L587" href="source/drivers/net/ethernet/smsc/smc91x.c#L587">587</a>         <a href="ident?i=SMC_SET_PTR">SMC_SET_PTR</a>(<a href="ident?i=lp">lp</a>, <a href="ident?i=PTR_AUTOINC">PTR_AUTOINC</a>);
<a name="L588" href="source/drivers/net/ethernet/smsc/smc91x.c#L588">588</a> 
<a name="L589" href="source/drivers/net/ethernet/smsc/smc91x.c#L589">589</a>         <a href="ident?i=buf">buf</a> = <a href="ident?i=skb">skb</a>-&gt;<a href="ident?i=data">data</a>;
<a name="L590" href="source/drivers/net/ethernet/smsc/smc91x.c#L590">590</a>         <a href="ident?i=len">len</a> = <a href="ident?i=skb">skb</a>-&gt;<a href="ident?i=len">len</a>;
<a name="L591" href="source/drivers/net/ethernet/smsc/smc91x.c#L591">591</a>         <a href="ident?i=DBG">DBG</a>(2, <a href="ident?i=dev">dev</a>, <i>"TX PNR 0x%x LENGTH 0x%04x (%d) BUF 0x%p\n"</i>,
<a name="L592" href="source/drivers/net/ethernet/smsc/smc91x.c#L592">592</a>             packet_no, <a href="ident?i=len">len</a>, <a href="ident?i=len">len</a>, <a href="ident?i=buf">buf</a>);
<a name="L593" href="source/drivers/net/ethernet/smsc/smc91x.c#L593">593</a>         <a href="ident?i=PRINT_PKT">PRINT_PKT</a>(<a href="ident?i=buf">buf</a>, <a href="ident?i=len">len</a>);
<a name="L594" href="source/drivers/net/ethernet/smsc/smc91x.c#L594">594</a> 
<a name="L595" href="source/drivers/net/ethernet/smsc/smc91x.c#L595">595</a>         <b><i>/*</i></b>
<a name="L596" href="source/drivers/net/ethernet/smsc/smc91x.c#L596">596</a> <b><i>         * Send the packet length (+6 for status words, length, and ctl.</i></b>
<a name="L597" href="source/drivers/net/ethernet/smsc/smc91x.c#L597">597</a> <b><i>         * The card will pad to 64 bytes with zeroes if packet is too small.</i></b>
<a name="L598" href="source/drivers/net/ethernet/smsc/smc91x.c#L598">598</a> <b><i>         */</i></b>
<a name="L599" href="source/drivers/net/ethernet/smsc/smc91x.c#L599">599</a>         <a href="ident?i=SMC_PUT_PKT_HDR">SMC_PUT_PKT_HDR</a>(<a href="ident?i=lp">lp</a>, 0, <a href="ident?i=len">len</a> + 6);
<a name="L600" href="source/drivers/net/ethernet/smsc/smc91x.c#L600">600</a> 
<a name="L601" href="source/drivers/net/ethernet/smsc/smc91x.c#L601">601</a>         <b><i>/* send the actual data */</i></b>
<a name="L602" href="source/drivers/net/ethernet/smsc/smc91x.c#L602">602</a>         <a href="ident?i=SMC_PUSH_DATA">SMC_PUSH_DATA</a>(<a href="ident?i=lp">lp</a>, <a href="ident?i=buf">buf</a>, <a href="ident?i=len">len</a> &amp; ~1);
<a name="L603" href="source/drivers/net/ethernet/smsc/smc91x.c#L603">603</a> 
<a name="L604" href="source/drivers/net/ethernet/smsc/smc91x.c#L604">604</a>         <b><i>/* Send final ctl word with the last byte if there is one */</i></b>
<a name="L605" href="source/drivers/net/ethernet/smsc/smc91x.c#L605">605</a>         <a href="ident?i=SMC_outw">SMC_outw</a>(((<a href="ident?i=len">len</a> &amp; 1) ? (0x2000 | <a href="ident?i=buf">buf</a>[<a href="ident?i=len">len</a>-1]) : 0), <a href="ident?i=ioaddr">ioaddr</a>, <a href="ident?i=DATA_REG">DATA_REG</a>(<a href="ident?i=lp">lp</a>));
<a name="L606" href="source/drivers/net/ethernet/smsc/smc91x.c#L606">606</a> 
<a name="L607" href="source/drivers/net/ethernet/smsc/smc91x.c#L607">607</a>         <b><i>/*</i></b>
<a name="L608" href="source/drivers/net/ethernet/smsc/smc91x.c#L608">608</a> <b><i>         * If THROTTLE_TX_PKTS is set, we stop the queue here. This will</i></b>
<a name="L609" href="source/drivers/net/ethernet/smsc/smc91x.c#L609">609</a> <b><i>         * have the effect of having at most one packet queued for TX</i></b>
<a name="L610" href="source/drivers/net/ethernet/smsc/smc91x.c#L610">610</a> <b><i>         * in the chip's memory at all time.</i></b>
<a name="L611" href="source/drivers/net/ethernet/smsc/smc91x.c#L611">611</a> <b><i>         *</i></b>
<a name="L612" href="source/drivers/net/ethernet/smsc/smc91x.c#L612">612</a> <b><i>         * If THROTTLE_TX_PKTS is not set then the queue is stopped only</i></b>
<a name="L613" href="source/drivers/net/ethernet/smsc/smc91x.c#L613">613</a> <b><i>         * when memory allocation (MC_ALLOC) does not succeed right away.</i></b>
<a name="L614" href="source/drivers/net/ethernet/smsc/smc91x.c#L614">614</a> <b><i>         */</i></b>
<a name="L615" href="source/drivers/net/ethernet/smsc/smc91x.c#L615">615</a>         if (<a href="ident?i=THROTTLE_TX_PKTS">THROTTLE_TX_PKTS</a>)
<a name="L616" href="source/drivers/net/ethernet/smsc/smc91x.c#L616">616</a>                 <a href="ident?i=netif_stop_queue">netif_stop_queue</a>(<a href="ident?i=dev">dev</a>);
<a name="L617" href="source/drivers/net/ethernet/smsc/smc91x.c#L617">617</a> 
<a name="L618" href="source/drivers/net/ethernet/smsc/smc91x.c#L618">618</a>         <b><i>/* queue the packet for TX */</i></b>
<a name="L619" href="source/drivers/net/ethernet/smsc/smc91x.c#L619">619</a>         <a href="ident?i=SMC_SET_MMU_CMD">SMC_SET_MMU_CMD</a>(<a href="ident?i=lp">lp</a>, <a href="ident?i=MC_ENQUEUE">MC_ENQUEUE</a>);
<a name="L620" href="source/drivers/net/ethernet/smsc/smc91x.c#L620">620</a>         <a href="ident?i=smc_special_unlock">smc_special_unlock</a>(&amp;<a href="ident?i=lp">lp</a>-&gt;<a href="ident?i=lock">lock</a>, <a href="ident?i=flags">flags</a>);
<a name="L621" href="source/drivers/net/ethernet/smsc/smc91x.c#L621">621</a> 
<a name="L622" href="source/drivers/net/ethernet/smsc/smc91x.c#L622">622</a>         <a href="ident?i=netif_trans_update">netif_trans_update</a>(<a href="ident?i=dev">dev</a>);
<a name="L623" href="source/drivers/net/ethernet/smsc/smc91x.c#L623">623</a>         <a href="ident?i=dev">dev</a>-&gt;<a href="ident?i=stats">stats</a>.tx_packets++;
<a name="L624" href="source/drivers/net/ethernet/smsc/smc91x.c#L624">624</a>         <a href="ident?i=dev">dev</a>-&gt;<a href="ident?i=stats">stats</a>.<a href="ident?i=tx_bytes">tx_bytes</a> += <a href="ident?i=len">len</a>;
<a name="L625" href="source/drivers/net/ethernet/smsc/smc91x.c#L625">625</a> 
<a name="L626" href="source/drivers/net/ethernet/smsc/smc91x.c#L626">626</a>         <a href="ident?i=SMC_ENABLE_INT">SMC_ENABLE_INT</a>(<a href="ident?i=lp">lp</a>, <a href="ident?i=IM_TX_INT">IM_TX_INT</a> | <a href="ident?i=IM_TX_EMPTY_INT">IM_TX_EMPTY_INT</a>);
<a name="L627" href="source/drivers/net/ethernet/smsc/smc91x.c#L627">627</a> 
<a name="L628" href="source/drivers/net/ethernet/smsc/smc91x.c#L628">628</a> <a href="ident?i=done">done</a>:   if (!<a href="ident?i=THROTTLE_TX_PKTS">THROTTLE_TX_PKTS</a>)
<a name="L629" href="source/drivers/net/ethernet/smsc/smc91x.c#L629">629</a>                 <a href="ident?i=netif_wake_queue">netif_wake_queue</a>(<a href="ident?i=dev">dev</a>);
<a name="L630" href="source/drivers/net/ethernet/smsc/smc91x.c#L630">630</a> 
<a name="L631" href="source/drivers/net/ethernet/smsc/smc91x.c#L631">631</a>         <a href="ident?i=dev_consume_skb_any">dev_consume_skb_any</a>(<a href="ident?i=skb">skb</a>);
<a name="L632" href="source/drivers/net/ethernet/smsc/smc91x.c#L632">632</a> }
<a name="L633" href="source/drivers/net/ethernet/smsc/smc91x.c#L633">633</a> 
<a name="L634" href="source/drivers/net/ethernet/smsc/smc91x.c#L634">634</a> <b><i>/*</i></b>
<a name="L635" href="source/drivers/net/ethernet/smsc/smc91x.c#L635">635</a> <b><i> * Since I am not sure if I will have enough room in the chip's ram</i></b>
<a name="L636" href="source/drivers/net/ethernet/smsc/smc91x.c#L636">636</a> <b><i> * to store the packet, I call this routine which either sends it</i></b>
<a name="L637" href="source/drivers/net/ethernet/smsc/smc91x.c#L637">637</a> <b><i> * now, or set the card to generates an interrupt when ready</i></b>
<a name="L638" href="source/drivers/net/ethernet/smsc/smc91x.c#L638">638</a> <b><i> * for the packet.</i></b>
<a name="L639" href="source/drivers/net/ethernet/smsc/smc91x.c#L639">639</a> <b><i> */</i></b>
<a name="L640" href="source/drivers/net/ethernet/smsc/smc91x.c#L640">640</a> static int <a href="ident?i=smc_hard_start_xmit">smc_hard_start_xmit</a>(struct <a href="ident?i=sk_buff">sk_buff</a> *<a href="ident?i=skb">skb</a>, struct <a href="ident?i=net_device">net_device</a> *<a href="ident?i=dev">dev</a>)
<a name="L641" href="source/drivers/net/ethernet/smsc/smc91x.c#L641">641</a> {
<a name="L642" href="source/drivers/net/ethernet/smsc/smc91x.c#L642">642</a>         struct <a href="ident?i=smc_local">smc_local</a> *<a href="ident?i=lp">lp</a> = <a href="ident?i=netdev_priv">netdev_priv</a>(<a href="ident?i=dev">dev</a>);
<a name="L643" href="source/drivers/net/ethernet/smsc/smc91x.c#L643">643</a>         void <a href="ident?i=__iomem">__iomem</a> *<a href="ident?i=ioaddr">ioaddr</a> = <a href="ident?i=lp">lp</a>-&gt;<a href="ident?i=base">base</a>;
<a name="L644" href="source/drivers/net/ethernet/smsc/smc91x.c#L644">644</a>         unsigned int numPages, poll_count, <a href="ident?i=status">status</a>;
<a name="L645" href="source/drivers/net/ethernet/smsc/smc91x.c#L645">645</a>         unsigned long <a href="ident?i=flags">flags</a>;
<a name="L646" href="source/drivers/net/ethernet/smsc/smc91x.c#L646">646</a> 
<a name="L647" href="source/drivers/net/ethernet/smsc/smc91x.c#L647">647</a>         <a href="ident?i=DBG">DBG</a>(3, <a href="ident?i=dev">dev</a>, <i>"%s\n"</i>, <a href="ident?i=__func__">__func__</a>);
<a name="L648" href="source/drivers/net/ethernet/smsc/smc91x.c#L648">648</a> 
<a name="L649" href="source/drivers/net/ethernet/smsc/smc91x.c#L649">649</a>         <a href="ident?i=BUG_ON">BUG_ON</a>(<a href="ident?i=lp">lp</a>-&gt;pending_tx_skb != <a href="ident?i=NULL">NULL</a>);
<a name="L650" href="source/drivers/net/ethernet/smsc/smc91x.c#L650">650</a> 
<a name="L651" href="source/drivers/net/ethernet/smsc/smc91x.c#L651">651</a>         <b><i>/*</i></b>
<a name="L652" href="source/drivers/net/ethernet/smsc/smc91x.c#L652">652</a> <b><i>         * The MMU wants the number of pages to be the number of 256 bytes</i></b>
<a name="L653" href="source/drivers/net/ethernet/smsc/smc91x.c#L653">653</a> <b><i>         * 'pages', minus 1 (since a packet can't ever have 0 pages :))</i></b>
<a name="L654" href="source/drivers/net/ethernet/smsc/smc91x.c#L654">654</a> <b><i>         *</i></b>
<a name="L655" href="source/drivers/net/ethernet/smsc/smc91x.c#L655">655</a> <b><i>         * The 91C111 ignores the size bits, but earlier models don't.</i></b>
<a name="L656" href="source/drivers/net/ethernet/smsc/smc91x.c#L656">656</a> <b><i>         *</i></b>
<a name="L657" href="source/drivers/net/ethernet/smsc/smc91x.c#L657">657</a> <b><i>         * Pkt size for allocating is data length +6 (for additional status</i></b>
<a name="L658" href="source/drivers/net/ethernet/smsc/smc91x.c#L658">658</a> <b><i>         * words, length and ctl)</i></b>
<a name="L659" href="source/drivers/net/ethernet/smsc/smc91x.c#L659">659</a> <b><i>         *</i></b>
<a name="L660" href="source/drivers/net/ethernet/smsc/smc91x.c#L660">660</a> <b><i>         * If odd size then last byte is included in ctl word.</i></b>
<a name="L661" href="source/drivers/net/ethernet/smsc/smc91x.c#L661">661</a> <b><i>         */</i></b>
<a name="L662" href="source/drivers/net/ethernet/smsc/smc91x.c#L662">662</a>         numPages = ((<a href="ident?i=skb">skb</a>-&gt;<a href="ident?i=len">len</a> &amp; ~1) + (6 - 1)) &gt;&gt; 8;
<a name="L663" href="source/drivers/net/ethernet/smsc/smc91x.c#L663">663</a>         if (<a href="ident?i=unlikely">unlikely</a>(numPages &gt; 7)) {
<a name="L664" href="source/drivers/net/ethernet/smsc/smc91x.c#L664">664</a>                 <a href="ident?i=netdev_warn">netdev_warn</a>(<a href="ident?i=dev">dev</a>, <i>"Far too big packet error.\n"</i>);
<a name="L665" href="source/drivers/net/ethernet/smsc/smc91x.c#L665">665</a>                 <a href="ident?i=dev">dev</a>-&gt;<a href="ident?i=stats">stats</a>.tx_errors++;
<a name="L666" href="source/drivers/net/ethernet/smsc/smc91x.c#L666">666</a>                 <a href="ident?i=dev">dev</a>-&gt;<a href="ident?i=stats">stats</a>.tx_dropped++;
<a name="L667" href="source/drivers/net/ethernet/smsc/smc91x.c#L667">667</a>                 <a href="ident?i=dev_kfree_skb_any">dev_kfree_skb_any</a>(<a href="ident?i=skb">skb</a>);
<a name="L668" href="source/drivers/net/ethernet/smsc/smc91x.c#L668">668</a>                 return <a href="ident?i=NETDEV_TX_OK">NETDEV_TX_OK</a>;
<a name="L669" href="source/drivers/net/ethernet/smsc/smc91x.c#L669">669</a>         }
<a name="L670" href="source/drivers/net/ethernet/smsc/smc91x.c#L670">670</a> 
<a name="L671" href="source/drivers/net/ethernet/smsc/smc91x.c#L671">671</a>         <a href="ident?i=smc_special_lock">smc_special_lock</a>(&amp;<a href="ident?i=lp">lp</a>-&gt;<a href="ident?i=lock">lock</a>, <a href="ident?i=flags">flags</a>);
<a name="L672" href="source/drivers/net/ethernet/smsc/smc91x.c#L672">672</a> 
<a name="L673" href="source/drivers/net/ethernet/smsc/smc91x.c#L673">673</a>         <b><i>/* now, try to allocate the memory */</i></b>
<a name="L674" href="source/drivers/net/ethernet/smsc/smc91x.c#L674">674</a>         <a href="ident?i=SMC_SET_MMU_CMD">SMC_SET_MMU_CMD</a>(<a href="ident?i=lp">lp</a>, <a href="ident?i=MC_ALLOC">MC_ALLOC</a> | numPages);
<a name="L675" href="source/drivers/net/ethernet/smsc/smc91x.c#L675">675</a> 
<a name="L676" href="source/drivers/net/ethernet/smsc/smc91x.c#L676">676</a>         <b><i>/*</i></b>
<a name="L677" href="source/drivers/net/ethernet/smsc/smc91x.c#L677">677</a> <b><i>         * Poll the chip for a short amount of time in case the</i></b>
<a name="L678" href="source/drivers/net/ethernet/smsc/smc91x.c#L678">678</a> <b><i>         * allocation succeeds quickly.</i></b>
<a name="L679" href="source/drivers/net/ethernet/smsc/smc91x.c#L679">679</a> <b><i>         */</i></b>
<a name="L680" href="source/drivers/net/ethernet/smsc/smc91x.c#L680">680</a>         poll_count = <a href="ident?i=MEMORY_WAIT_TIME">MEMORY_WAIT_TIME</a>;
<a name="L681" href="source/drivers/net/ethernet/smsc/smc91x.c#L681">681</a>         do {
<a name="L682" href="source/drivers/net/ethernet/smsc/smc91x.c#L682">682</a>                 <a href="ident?i=status">status</a> = <a href="ident?i=SMC_GET_INT">SMC_GET_INT</a>(<a href="ident?i=lp">lp</a>);
<a name="L683" href="source/drivers/net/ethernet/smsc/smc91x.c#L683">683</a>                 if (<a href="ident?i=status">status</a> &amp; <a href="ident?i=IM_ALLOC_INT">IM_ALLOC_INT</a>) {
<a name="L684" href="source/drivers/net/ethernet/smsc/smc91x.c#L684">684</a>                         <a href="ident?i=SMC_ACK_INT">SMC_ACK_INT</a>(<a href="ident?i=lp">lp</a>, <a href="ident?i=IM_ALLOC_INT">IM_ALLOC_INT</a>);
<a name="L685" href="source/drivers/net/ethernet/smsc/smc91x.c#L685">685</a>                         break;
<a name="L686" href="source/drivers/net/ethernet/smsc/smc91x.c#L686">686</a>                 }
<a name="L687" href="source/drivers/net/ethernet/smsc/smc91x.c#L687">687</a>         } while (--poll_count);
<a name="L688" href="source/drivers/net/ethernet/smsc/smc91x.c#L688">688</a> 
<a name="L689" href="source/drivers/net/ethernet/smsc/smc91x.c#L689">689</a>         <a href="ident?i=smc_special_unlock">smc_special_unlock</a>(&amp;<a href="ident?i=lp">lp</a>-&gt;<a href="ident?i=lock">lock</a>, <a href="ident?i=flags">flags</a>);
<a name="L690" href="source/drivers/net/ethernet/smsc/smc91x.c#L690">690</a> 
<a name="L691" href="source/drivers/net/ethernet/smsc/smc91x.c#L691">691</a>         <a href="ident?i=lp">lp</a>-&gt;pending_tx_skb = <a href="ident?i=skb">skb</a>;
<a name="L692" href="source/drivers/net/ethernet/smsc/smc91x.c#L692">692</a>         if (!poll_count) {
<a name="L693" href="source/drivers/net/ethernet/smsc/smc91x.c#L693">693</a>                 <b><i>/* oh well, wait until the chip finds memory later */</i></b>
<a name="L694" href="source/drivers/net/ethernet/smsc/smc91x.c#L694">694</a>                 <a href="ident?i=netif_stop_queue">netif_stop_queue</a>(<a href="ident?i=dev">dev</a>);
<a name="L695" href="source/drivers/net/ethernet/smsc/smc91x.c#L695">695</a>                 <a href="ident?i=DBG">DBG</a>(2, <a href="ident?i=dev">dev</a>, <i>"TX memory allocation deferred.\n"</i>);
<a name="L696" href="source/drivers/net/ethernet/smsc/smc91x.c#L696">696</a>                 <a href="ident?i=SMC_ENABLE_INT">SMC_ENABLE_INT</a>(<a href="ident?i=lp">lp</a>, <a href="ident?i=IM_ALLOC_INT">IM_ALLOC_INT</a>);
<a name="L697" href="source/drivers/net/ethernet/smsc/smc91x.c#L697">697</a>         } else {
<a name="L698" href="source/drivers/net/ethernet/smsc/smc91x.c#L698">698</a>                 <b><i>/*</i></b>
<a name="L699" href="source/drivers/net/ethernet/smsc/smc91x.c#L699">699</a> <b><i>                 * Allocation succeeded: push packet to the chip's own memory</i></b>
<a name="L700" href="source/drivers/net/ethernet/smsc/smc91x.c#L700">700</a> <b><i>                 * immediately.</i></b>
<a name="L701" href="source/drivers/net/ethernet/smsc/smc91x.c#L701">701</a> <b><i>                 */</i></b>
<a name="L702" href="source/drivers/net/ethernet/smsc/smc91x.c#L702">702</a>                 <a href="ident?i=smc_hardware_send_pkt">smc_hardware_send_pkt</a>((unsigned long)<a href="ident?i=dev">dev</a>);
<a name="L703" href="source/drivers/net/ethernet/smsc/smc91x.c#L703">703</a>         }
<a name="L704" href="source/drivers/net/ethernet/smsc/smc91x.c#L704">704</a> 
<a name="L705" href="source/drivers/net/ethernet/smsc/smc91x.c#L705">705</a>         return <a href="ident?i=NETDEV_TX_OK">NETDEV_TX_OK</a>;
<a name="L706" href="source/drivers/net/ethernet/smsc/smc91x.c#L706">706</a> }
<a name="L707" href="source/drivers/net/ethernet/smsc/smc91x.c#L707">707</a> 
<a name="L708" href="source/drivers/net/ethernet/smsc/smc91x.c#L708">708</a> <b><i>/*</i></b>
<a name="L709" href="source/drivers/net/ethernet/smsc/smc91x.c#L709">709</a> <b><i> * This handles a TX interrupt, which is only called when:</i></b>
<a name="L710" href="source/drivers/net/ethernet/smsc/smc91x.c#L710">710</a> <b><i> * - a TX error occurred, or</i></b>
<a name="L711" href="source/drivers/net/ethernet/smsc/smc91x.c#L711">711</a> <b><i> * - CTL_AUTO_RELEASE is not set and TX of a packet completed.</i></b>
<a name="L712" href="source/drivers/net/ethernet/smsc/smc91x.c#L712">712</a> <b><i> */</i></b>
<a name="L713" href="source/drivers/net/ethernet/smsc/smc91x.c#L713">713</a> static void <a href="ident?i=smc_tx">smc_tx</a>(struct <a href="ident?i=net_device">net_device</a> *<a href="ident?i=dev">dev</a>)
<a name="L714" href="source/drivers/net/ethernet/smsc/smc91x.c#L714">714</a> {
<a name="L715" href="source/drivers/net/ethernet/smsc/smc91x.c#L715">715</a>         struct <a href="ident?i=smc_local">smc_local</a> *<a href="ident?i=lp">lp</a> = <a href="ident?i=netdev_priv">netdev_priv</a>(<a href="ident?i=dev">dev</a>);
<a name="L716" href="source/drivers/net/ethernet/smsc/smc91x.c#L716">716</a>         void <a href="ident?i=__iomem">__iomem</a> *<a href="ident?i=ioaddr">ioaddr</a> = <a href="ident?i=lp">lp</a>-&gt;<a href="ident?i=base">base</a>;
<a name="L717" href="source/drivers/net/ethernet/smsc/smc91x.c#L717">717</a>         unsigned int saved_packet, packet_no, <a href="ident?i=tx_status">tx_status</a>, pkt_len;
<a name="L718" href="source/drivers/net/ethernet/smsc/smc91x.c#L718">718</a> 
<a name="L719" href="source/drivers/net/ethernet/smsc/smc91x.c#L719">719</a>         <a href="ident?i=DBG">DBG</a>(3, <a href="ident?i=dev">dev</a>, <i>"%s\n"</i>, <a href="ident?i=__func__">__func__</a>);
<a name="L720" href="source/drivers/net/ethernet/smsc/smc91x.c#L720">720</a> 
<a name="L721" href="source/drivers/net/ethernet/smsc/smc91x.c#L721">721</a>         <b><i>/* If the TX FIFO is empty then nothing to do */</i></b>
<a name="L722" href="source/drivers/net/ethernet/smsc/smc91x.c#L722">722</a>         packet_no = <a href="ident?i=SMC_GET_TXFIFO">SMC_GET_TXFIFO</a>(<a href="ident?i=lp">lp</a>);
<a name="L723" href="source/drivers/net/ethernet/smsc/smc91x.c#L723">723</a>         if (<a href="ident?i=unlikely">unlikely</a>(packet_no &amp; <a href="ident?i=TXFIFO_TEMPTY">TXFIFO_TEMPTY</a>)) {
<a name="L724" href="source/drivers/net/ethernet/smsc/smc91x.c#L724">724</a>                 <a href="ident?i=PRINTK">PRINTK</a>(<a href="ident?i=dev">dev</a>, <i>"smc_tx with nothing on FIFO.\n"</i>);
<a name="L725" href="source/drivers/net/ethernet/smsc/smc91x.c#L725">725</a>                 return;
<a name="L726" href="source/drivers/net/ethernet/smsc/smc91x.c#L726">726</a>         }
<a name="L727" href="source/drivers/net/ethernet/smsc/smc91x.c#L727">727</a> 
<a name="L728" href="source/drivers/net/ethernet/smsc/smc91x.c#L728">728</a>         <b><i>/* select packet to read from */</i></b>
<a name="L729" href="source/drivers/net/ethernet/smsc/smc91x.c#L729">729</a>         saved_packet = <a href="ident?i=SMC_GET_PN">SMC_GET_PN</a>(<a href="ident?i=lp">lp</a>);
<a name="L730" href="source/drivers/net/ethernet/smsc/smc91x.c#L730">730</a>         <a href="ident?i=SMC_SET_PN">SMC_SET_PN</a>(<a href="ident?i=lp">lp</a>, packet_no);
<a name="L731" href="source/drivers/net/ethernet/smsc/smc91x.c#L731">731</a> 
<a name="L732" href="source/drivers/net/ethernet/smsc/smc91x.c#L732">732</a>         <b><i>/* read the first word (status word) from this packet */</i></b>
<a name="L733" href="source/drivers/net/ethernet/smsc/smc91x.c#L733">733</a>         <a href="ident?i=SMC_SET_PTR">SMC_SET_PTR</a>(<a href="ident?i=lp">lp</a>, <a href="ident?i=PTR_AUTOINC">PTR_AUTOINC</a> | <a href="ident?i=PTR_READ">PTR_READ</a>);
<a name="L734" href="source/drivers/net/ethernet/smsc/smc91x.c#L734">734</a>         <a href="ident?i=SMC_GET_PKT_HDR">SMC_GET_PKT_HDR</a>(<a href="ident?i=lp">lp</a>, <a href="ident?i=tx_status">tx_status</a>, pkt_len);
<a name="L735" href="source/drivers/net/ethernet/smsc/smc91x.c#L735">735</a>         <a href="ident?i=DBG">DBG</a>(2, <a href="ident?i=dev">dev</a>, <i>"TX STATUS 0x%04x PNR 0x%02x\n"</i>,
<a name="L736" href="source/drivers/net/ethernet/smsc/smc91x.c#L736">736</a>             <a href="ident?i=tx_status">tx_status</a>, packet_no);
<a name="L737" href="source/drivers/net/ethernet/smsc/smc91x.c#L737">737</a> 
<a name="L738" href="source/drivers/net/ethernet/smsc/smc91x.c#L738">738</a>         if (!(<a href="ident?i=tx_status">tx_status</a> &amp; <a href="ident?i=ES_TX_SUC">ES_TX_SUC</a>))
<a name="L739" href="source/drivers/net/ethernet/smsc/smc91x.c#L739">739</a>                 <a href="ident?i=dev">dev</a>-&gt;<a href="ident?i=stats">stats</a>.tx_errors++;
<a name="L740" href="source/drivers/net/ethernet/smsc/smc91x.c#L740">740</a> 
<a name="L741" href="source/drivers/net/ethernet/smsc/smc91x.c#L741">741</a>         if (<a href="ident?i=tx_status">tx_status</a> &amp; <a href="ident?i=ES_LOSTCARR">ES_LOSTCARR</a>)
<a name="L742" href="source/drivers/net/ethernet/smsc/smc91x.c#L742">742</a>                 <a href="ident?i=dev">dev</a>-&gt;<a href="ident?i=stats">stats</a>.tx_carrier_errors++;
<a name="L743" href="source/drivers/net/ethernet/smsc/smc91x.c#L743">743</a> 
<a name="L744" href="source/drivers/net/ethernet/smsc/smc91x.c#L744">744</a>         if (<a href="ident?i=tx_status">tx_status</a> &amp; (<a href="ident?i=ES_LATCOL">ES_LATCOL</a> | <a href="ident?i=ES_16COL">ES_16COL</a>)) {
<a name="L745" href="source/drivers/net/ethernet/smsc/smc91x.c#L745">745</a>                 <a href="ident?i=PRINTK">PRINTK</a>(<a href="ident?i=dev">dev</a>, <i>"%s occurred on last xmit\n"</i>,
<a name="L746" href="source/drivers/net/ethernet/smsc/smc91x.c#L746">746</a>                        (<a href="ident?i=tx_status">tx_status</a> &amp; <a href="ident?i=ES_LATCOL">ES_LATCOL</a>) ?
<a name="L747" href="source/drivers/net/ethernet/smsc/smc91x.c#L747">747</a>                         <i>"late collision"</i> : <i>"too many collisions"</i>);
<a name="L748" href="source/drivers/net/ethernet/smsc/smc91x.c#L748">748</a>                 <a href="ident?i=dev">dev</a>-&gt;<a href="ident?i=stats">stats</a>.tx_window_errors++;
<a name="L749" href="source/drivers/net/ethernet/smsc/smc91x.c#L749">749</a>                 if (!(<a href="ident?i=dev">dev</a>-&gt;<a href="ident?i=stats">stats</a>.tx_window_errors &amp; 63) &amp;&amp; <a href="ident?i=net_ratelimit">net_ratelimit</a>()) {
<a name="L750" href="source/drivers/net/ethernet/smsc/smc91x.c#L750">750</a>                         <a href="ident?i=netdev_info">netdev_info</a>(<a href="ident?i=dev">dev</a>, <i>"unexpectedly large number of bad collisions. Please check duplex setting.\n"</i>);
<a name="L751" href="source/drivers/net/ethernet/smsc/smc91x.c#L751">751</a>                 }
<a name="L752" href="source/drivers/net/ethernet/smsc/smc91x.c#L752">752</a>         }
<a name="L753" href="source/drivers/net/ethernet/smsc/smc91x.c#L753">753</a> 
<a name="L754" href="source/drivers/net/ethernet/smsc/smc91x.c#L754">754</a>         <b><i>/* kill the packet */</i></b>
<a name="L755" href="source/drivers/net/ethernet/smsc/smc91x.c#L755">755</a>         <a href="ident?i=SMC_WAIT_MMU_BUSY">SMC_WAIT_MMU_BUSY</a>(<a href="ident?i=lp">lp</a>);
<a name="L756" href="source/drivers/net/ethernet/smsc/smc91x.c#L756">756</a>         <a href="ident?i=SMC_SET_MMU_CMD">SMC_SET_MMU_CMD</a>(<a href="ident?i=lp">lp</a>, <a href="ident?i=MC_FREEPKT">MC_FREEPKT</a>);
<a name="L757" href="source/drivers/net/ethernet/smsc/smc91x.c#L757">757</a> 
<a name="L758" href="source/drivers/net/ethernet/smsc/smc91x.c#L758">758</a>         <b><i>/* Don't restore Packet Number Reg until busy bit is cleared */</i></b>
<a name="L759" href="source/drivers/net/ethernet/smsc/smc91x.c#L759">759</a>         <a href="ident?i=SMC_WAIT_MMU_BUSY">SMC_WAIT_MMU_BUSY</a>(<a href="ident?i=lp">lp</a>);
<a name="L760" href="source/drivers/net/ethernet/smsc/smc91x.c#L760">760</a>         <a href="ident?i=SMC_SET_PN">SMC_SET_PN</a>(<a href="ident?i=lp">lp</a>, saved_packet);
<a name="L761" href="source/drivers/net/ethernet/smsc/smc91x.c#L761">761</a> 
<a name="L762" href="source/drivers/net/ethernet/smsc/smc91x.c#L762">762</a>         <b><i>/* re-enable transmit */</i></b>
<a name="L763" href="source/drivers/net/ethernet/smsc/smc91x.c#L763">763</a>         <a href="ident?i=SMC_SELECT_BANK">SMC_SELECT_BANK</a>(<a href="ident?i=lp">lp</a>, 0);
<a name="L764" href="source/drivers/net/ethernet/smsc/smc91x.c#L764">764</a>         <a href="ident?i=SMC_SET_TCR">SMC_SET_TCR</a>(<a href="ident?i=lp">lp</a>, <a href="ident?i=lp">lp</a>-&gt;tcr_cur_mode);
<a name="L765" href="source/drivers/net/ethernet/smsc/smc91x.c#L765">765</a>         <a href="ident?i=SMC_SELECT_BANK">SMC_SELECT_BANK</a>(<a href="ident?i=lp">lp</a>, 2);
<a name="L766" href="source/drivers/net/ethernet/smsc/smc91x.c#L766">766</a> }
<a name="L767" href="source/drivers/net/ethernet/smsc/smc91x.c#L767">767</a> 
<a name="L768" href="source/drivers/net/ethernet/smsc/smc91x.c#L768">768</a> 
<a name="L769" href="source/drivers/net/ethernet/smsc/smc91x.c#L769">769</a> <b><i>/*---PHY CONTROL AND CONFIGURATION-----------------------------------------*/</i></b>
<a name="L770" href="source/drivers/net/ethernet/smsc/smc91x.c#L770">770</a> 
<a name="L771" href="source/drivers/net/ethernet/smsc/smc91x.c#L771">771</a> static void <a href="ident?i=smc_mii_out">smc_mii_out</a>(struct <a href="ident?i=net_device">net_device</a> *<a href="ident?i=dev">dev</a>, unsigned int <a href="ident?i=val">val</a>, int <a href="ident?i=bits">bits</a>)
<a name="L772" href="source/drivers/net/ethernet/smsc/smc91x.c#L772">772</a> {
<a name="L773" href="source/drivers/net/ethernet/smsc/smc91x.c#L773">773</a>         struct <a href="ident?i=smc_local">smc_local</a> *<a href="ident?i=lp">lp</a> = <a href="ident?i=netdev_priv">netdev_priv</a>(<a href="ident?i=dev">dev</a>);
<a name="L774" href="source/drivers/net/ethernet/smsc/smc91x.c#L774">774</a>         void <a href="ident?i=__iomem">__iomem</a> *<a href="ident?i=ioaddr">ioaddr</a> = <a href="ident?i=lp">lp</a>-&gt;<a href="ident?i=base">base</a>;
<a name="L775" href="source/drivers/net/ethernet/smsc/smc91x.c#L775">775</a>         unsigned int mii_reg, <a href="ident?i=mask">mask</a>;
<a name="L776" href="source/drivers/net/ethernet/smsc/smc91x.c#L776">776</a> 
<a name="L777" href="source/drivers/net/ethernet/smsc/smc91x.c#L777">777</a>         mii_reg = <a href="ident?i=SMC_GET_MII">SMC_GET_MII</a>(<a href="ident?i=lp">lp</a>) &amp; ~(<a href="ident?i=MII_MCLK">MII_MCLK</a> | <a href="ident?i=MII_MDOE">MII_MDOE</a> | <a href="ident?i=MII_MDO">MII_MDO</a>);
<a name="L778" href="source/drivers/net/ethernet/smsc/smc91x.c#L778">778</a>         mii_reg |= <a href="ident?i=MII_MDOE">MII_MDOE</a>;
<a name="L779" href="source/drivers/net/ethernet/smsc/smc91x.c#L779">779</a> 
<a name="L780" href="source/drivers/net/ethernet/smsc/smc91x.c#L780">780</a>         for (<a href="ident?i=mask">mask</a> = 1 &lt;&lt; (<a href="ident?i=bits">bits</a> - 1); <a href="ident?i=mask">mask</a>; <a href="ident?i=mask">mask</a> &gt;&gt;= 1) {
<a name="L781" href="source/drivers/net/ethernet/smsc/smc91x.c#L781">781</a>                 if (<a href="ident?i=val">val</a> &amp; <a href="ident?i=mask">mask</a>)
<a name="L782" href="source/drivers/net/ethernet/smsc/smc91x.c#L782">782</a>                         mii_reg |= <a href="ident?i=MII_MDO">MII_MDO</a>;
<a name="L783" href="source/drivers/net/ethernet/smsc/smc91x.c#L783">783</a>                 else
<a name="L784" href="source/drivers/net/ethernet/smsc/smc91x.c#L784">784</a>                         mii_reg &amp;= ~MII_MDO;
<a name="L785" href="source/drivers/net/ethernet/smsc/smc91x.c#L785">785</a> 
<a name="L786" href="source/drivers/net/ethernet/smsc/smc91x.c#L786">786</a>                 <a href="ident?i=SMC_SET_MII">SMC_SET_MII</a>(<a href="ident?i=lp">lp</a>, mii_reg);
<a name="L787" href="source/drivers/net/ethernet/smsc/smc91x.c#L787">787</a>                 <a href="ident?i=udelay">udelay</a>(<a href="ident?i=MII_DELAY">MII_DELAY</a>);
<a name="L788" href="source/drivers/net/ethernet/smsc/smc91x.c#L788">788</a>                 <a href="ident?i=SMC_SET_MII">SMC_SET_MII</a>(<a href="ident?i=lp">lp</a>, mii_reg | <a href="ident?i=MII_MCLK">MII_MCLK</a>);
<a name="L789" href="source/drivers/net/ethernet/smsc/smc91x.c#L789">789</a>                 <a href="ident?i=udelay">udelay</a>(<a href="ident?i=MII_DELAY">MII_DELAY</a>);
<a name="L790" href="source/drivers/net/ethernet/smsc/smc91x.c#L790">790</a>         }
<a name="L791" href="source/drivers/net/ethernet/smsc/smc91x.c#L791">791</a> }
<a name="L792" href="source/drivers/net/ethernet/smsc/smc91x.c#L792">792</a> 
<a name="L793" href="source/drivers/net/ethernet/smsc/smc91x.c#L793">793</a> static unsigned int <a href="ident?i=smc_mii_in">smc_mii_in</a>(struct <a href="ident?i=net_device">net_device</a> *<a href="ident?i=dev">dev</a>, int <a href="ident?i=bits">bits</a>)
<a name="L794" href="source/drivers/net/ethernet/smsc/smc91x.c#L794">794</a> {
<a name="L795" href="source/drivers/net/ethernet/smsc/smc91x.c#L795">795</a>         struct <a href="ident?i=smc_local">smc_local</a> *<a href="ident?i=lp">lp</a> = <a href="ident?i=netdev_priv">netdev_priv</a>(<a href="ident?i=dev">dev</a>);
<a name="L796" href="source/drivers/net/ethernet/smsc/smc91x.c#L796">796</a>         void <a href="ident?i=__iomem">__iomem</a> *<a href="ident?i=ioaddr">ioaddr</a> = <a href="ident?i=lp">lp</a>-&gt;<a href="ident?i=base">base</a>;
<a name="L797" href="source/drivers/net/ethernet/smsc/smc91x.c#L797">797</a>         unsigned int mii_reg, <a href="ident?i=mask">mask</a>, <a href="ident?i=val">val</a>;
<a name="L798" href="source/drivers/net/ethernet/smsc/smc91x.c#L798">798</a> 
<a name="L799" href="source/drivers/net/ethernet/smsc/smc91x.c#L799">799</a>         mii_reg = <a href="ident?i=SMC_GET_MII">SMC_GET_MII</a>(<a href="ident?i=lp">lp</a>) &amp; ~(<a href="ident?i=MII_MCLK">MII_MCLK</a> | <a href="ident?i=MII_MDOE">MII_MDOE</a> | <a href="ident?i=MII_MDO">MII_MDO</a>);
<a name="L800" href="source/drivers/net/ethernet/smsc/smc91x.c#L800">800</a>         <a href="ident?i=SMC_SET_MII">SMC_SET_MII</a>(<a href="ident?i=lp">lp</a>, mii_reg);
<a name="L801" href="source/drivers/net/ethernet/smsc/smc91x.c#L801">801</a> 
<a name="L802" href="source/drivers/net/ethernet/smsc/smc91x.c#L802">802</a>         for (<a href="ident?i=mask">mask</a> = 1 &lt;&lt; (<a href="ident?i=bits">bits</a> - 1), <a href="ident?i=val">val</a> = 0; <a href="ident?i=mask">mask</a>; <a href="ident?i=mask">mask</a> &gt;&gt;= 1) {
<a name="L803" href="source/drivers/net/ethernet/smsc/smc91x.c#L803">803</a>                 if (<a href="ident?i=SMC_GET_MII">SMC_GET_MII</a>(<a href="ident?i=lp">lp</a>) &amp; <a href="ident?i=MII_MDI">MII_MDI</a>)
<a name="L804" href="source/drivers/net/ethernet/smsc/smc91x.c#L804">804</a>                         <a href="ident?i=val">val</a> |= <a href="ident?i=mask">mask</a>;
<a name="L805" href="source/drivers/net/ethernet/smsc/smc91x.c#L805">805</a> 
<a name="L806" href="source/drivers/net/ethernet/smsc/smc91x.c#L806">806</a>                 <a href="ident?i=SMC_SET_MII">SMC_SET_MII</a>(<a href="ident?i=lp">lp</a>, mii_reg);
<a name="L807" href="source/drivers/net/ethernet/smsc/smc91x.c#L807">807</a>                 <a href="ident?i=udelay">udelay</a>(<a href="ident?i=MII_DELAY">MII_DELAY</a>);
<a name="L808" href="source/drivers/net/ethernet/smsc/smc91x.c#L808">808</a>                 <a href="ident?i=SMC_SET_MII">SMC_SET_MII</a>(<a href="ident?i=lp">lp</a>, mii_reg | <a href="ident?i=MII_MCLK">MII_MCLK</a>);
<a name="L809" href="source/drivers/net/ethernet/smsc/smc91x.c#L809">809</a>                 <a href="ident?i=udelay">udelay</a>(<a href="ident?i=MII_DELAY">MII_DELAY</a>);
<a name="L810" href="source/drivers/net/ethernet/smsc/smc91x.c#L810">810</a>         }
<a name="L811" href="source/drivers/net/ethernet/smsc/smc91x.c#L811">811</a> 
<a name="L812" href="source/drivers/net/ethernet/smsc/smc91x.c#L812">812</a>         return <a href="ident?i=val">val</a>;
<a name="L813" href="source/drivers/net/ethernet/smsc/smc91x.c#L813">813</a> }
<a name="L814" href="source/drivers/net/ethernet/smsc/smc91x.c#L814">814</a> 
<a name="L815" href="source/drivers/net/ethernet/smsc/smc91x.c#L815">815</a> <b><i>/*</i></b>
<a name="L816" href="source/drivers/net/ethernet/smsc/smc91x.c#L816">816</a> <b><i> * Reads a register from the MII Management serial interface</i></b>
<a name="L817" href="source/drivers/net/ethernet/smsc/smc91x.c#L817">817</a> <b><i> */</i></b>
<a name="L818" href="source/drivers/net/ethernet/smsc/smc91x.c#L818">818</a> static int <a href="ident?i=smc_phy_read">smc_phy_read</a>(struct <a href="ident?i=net_device">net_device</a> *<a href="ident?i=dev">dev</a>, int <a href="ident?i=phyaddr">phyaddr</a>, int phyreg)
<a name="L819" href="source/drivers/net/ethernet/smsc/smc91x.c#L819">819</a> {
<a name="L820" href="source/drivers/net/ethernet/smsc/smc91x.c#L820">820</a>         struct <a href="ident?i=smc_local">smc_local</a> *<a href="ident?i=lp">lp</a> = <a href="ident?i=netdev_priv">netdev_priv</a>(<a href="ident?i=dev">dev</a>);
<a name="L821" href="source/drivers/net/ethernet/smsc/smc91x.c#L821">821</a>         void <a href="ident?i=__iomem">__iomem</a> *<a href="ident?i=ioaddr">ioaddr</a> = <a href="ident?i=lp">lp</a>-&gt;<a href="ident?i=base">base</a>;
<a name="L822" href="source/drivers/net/ethernet/smsc/smc91x.c#L822">822</a>         unsigned int phydata;
<a name="L823" href="source/drivers/net/ethernet/smsc/smc91x.c#L823">823</a> 
<a name="L824" href="source/drivers/net/ethernet/smsc/smc91x.c#L824">824</a>         <a href="ident?i=SMC_SELECT_BANK">SMC_SELECT_BANK</a>(<a href="ident?i=lp">lp</a>, 3);
<a name="L825" href="source/drivers/net/ethernet/smsc/smc91x.c#L825">825</a> 
<a name="L826" href="source/drivers/net/ethernet/smsc/smc91x.c#L826">826</a>         <b><i>/* Idle - 32 ones */</i></b>
<a name="L827" href="source/drivers/net/ethernet/smsc/smc91x.c#L827">827</a>         <a href="ident?i=smc_mii_out">smc_mii_out</a>(<a href="ident?i=dev">dev</a>, 0xffffffff, 32);
<a name="L828" href="source/drivers/net/ethernet/smsc/smc91x.c#L828">828</a> 
<a name="L829" href="source/drivers/net/ethernet/smsc/smc91x.c#L829">829</a>         <b><i>/* Start code (01) + read (10) + phyaddr + phyreg */</i></b>
<a name="L830" href="source/drivers/net/ethernet/smsc/smc91x.c#L830">830</a>         <a href="ident?i=smc_mii_out">smc_mii_out</a>(<a href="ident?i=dev">dev</a>, 6 &lt;&lt; 10 | <a href="ident?i=phyaddr">phyaddr</a> &lt;&lt; 5 | phyreg, 14);
<a name="L831" href="source/drivers/net/ethernet/smsc/smc91x.c#L831">831</a> 
<a name="L832" href="source/drivers/net/ethernet/smsc/smc91x.c#L832">832</a>         <b><i>/* Turnaround (2bits) + phydata */</i></b>
<a name="L833" href="source/drivers/net/ethernet/smsc/smc91x.c#L833">833</a>         phydata = <a href="ident?i=smc_mii_in">smc_mii_in</a>(<a href="ident?i=dev">dev</a>, 18);
<a name="L834" href="source/drivers/net/ethernet/smsc/smc91x.c#L834">834</a> 
<a name="L835" href="source/drivers/net/ethernet/smsc/smc91x.c#L835">835</a>         <b><i>/* Return to idle state */</i></b>
<a name="L836" href="source/drivers/net/ethernet/smsc/smc91x.c#L836">836</a>         <a href="ident?i=SMC_SET_MII">SMC_SET_MII</a>(<a href="ident?i=lp">lp</a>, <a href="ident?i=SMC_GET_MII">SMC_GET_MII</a>(<a href="ident?i=lp">lp</a>) &amp; ~(<a href="ident?i=MII_MCLK">MII_MCLK</a>|<a href="ident?i=MII_MDOE">MII_MDOE</a>|<a href="ident?i=MII_MDO">MII_MDO</a>));
<a name="L837" href="source/drivers/net/ethernet/smsc/smc91x.c#L837">837</a> 
<a name="L838" href="source/drivers/net/ethernet/smsc/smc91x.c#L838">838</a>         <a href="ident?i=DBG">DBG</a>(3, <a href="ident?i=dev">dev</a>, <i>"%s: phyaddr=0x%x, phyreg=0x%x, phydata=0x%x\n"</i>,
<a name="L839" href="source/drivers/net/ethernet/smsc/smc91x.c#L839">839</a>             <a href="ident?i=__func__">__func__</a>, <a href="ident?i=phyaddr">phyaddr</a>, phyreg, phydata);
<a name="L840" href="source/drivers/net/ethernet/smsc/smc91x.c#L840">840</a> 
<a name="L841" href="source/drivers/net/ethernet/smsc/smc91x.c#L841">841</a>         <a href="ident?i=SMC_SELECT_BANK">SMC_SELECT_BANK</a>(<a href="ident?i=lp">lp</a>, 2);
<a name="L842" href="source/drivers/net/ethernet/smsc/smc91x.c#L842">842</a>         return phydata;
<a name="L843" href="source/drivers/net/ethernet/smsc/smc91x.c#L843">843</a> }
<a name="L844" href="source/drivers/net/ethernet/smsc/smc91x.c#L844">844</a> 
<a name="L845" href="source/drivers/net/ethernet/smsc/smc91x.c#L845">845</a> <b><i>/*</i></b>
<a name="L846" href="source/drivers/net/ethernet/smsc/smc91x.c#L846">846</a> <b><i> * Writes a register to the MII Management serial interface</i></b>
<a name="L847" href="source/drivers/net/ethernet/smsc/smc91x.c#L847">847</a> <b><i> */</i></b>
<a name="L848" href="source/drivers/net/ethernet/smsc/smc91x.c#L848">848</a> static void <a href="ident?i=smc_phy_write">smc_phy_write</a>(struct <a href="ident?i=net_device">net_device</a> *<a href="ident?i=dev">dev</a>, int <a href="ident?i=phyaddr">phyaddr</a>, int phyreg,
<a name="L849" href="source/drivers/net/ethernet/smsc/smc91x.c#L849">849</a>                           int phydata)
<a name="L850" href="source/drivers/net/ethernet/smsc/smc91x.c#L850">850</a> {
<a name="L851" href="source/drivers/net/ethernet/smsc/smc91x.c#L851">851</a>         struct <a href="ident?i=smc_local">smc_local</a> *<a href="ident?i=lp">lp</a> = <a href="ident?i=netdev_priv">netdev_priv</a>(<a href="ident?i=dev">dev</a>);
<a name="L852" href="source/drivers/net/ethernet/smsc/smc91x.c#L852">852</a>         void <a href="ident?i=__iomem">__iomem</a> *<a href="ident?i=ioaddr">ioaddr</a> = <a href="ident?i=lp">lp</a>-&gt;<a href="ident?i=base">base</a>;
<a name="L853" href="source/drivers/net/ethernet/smsc/smc91x.c#L853">853</a> 
<a name="L854" href="source/drivers/net/ethernet/smsc/smc91x.c#L854">854</a>         <a href="ident?i=SMC_SELECT_BANK">SMC_SELECT_BANK</a>(<a href="ident?i=lp">lp</a>, 3);
<a name="L855" href="source/drivers/net/ethernet/smsc/smc91x.c#L855">855</a> 
<a name="L856" href="source/drivers/net/ethernet/smsc/smc91x.c#L856">856</a>         <b><i>/* Idle - 32 ones */</i></b>
<a name="L857" href="source/drivers/net/ethernet/smsc/smc91x.c#L857">857</a>         <a href="ident?i=smc_mii_out">smc_mii_out</a>(<a href="ident?i=dev">dev</a>, 0xffffffff, 32);
<a name="L858" href="source/drivers/net/ethernet/smsc/smc91x.c#L858">858</a> 
<a name="L859" href="source/drivers/net/ethernet/smsc/smc91x.c#L859">859</a>         <b><i>/* Start code (01) + write (01) + phyaddr + phyreg + turnaround + phydata */</i></b>
<a name="L860" href="source/drivers/net/ethernet/smsc/smc91x.c#L860">860</a>         <a href="ident?i=smc_mii_out">smc_mii_out</a>(<a href="ident?i=dev">dev</a>, 5 &lt;&lt; 28 | <a href="ident?i=phyaddr">phyaddr</a> &lt;&lt; 23 | phyreg &lt;&lt; 18 | 2 &lt;&lt; 16 | phydata, 32);
<a name="L861" href="source/drivers/net/ethernet/smsc/smc91x.c#L861">861</a> 
<a name="L862" href="source/drivers/net/ethernet/smsc/smc91x.c#L862">862</a>         <b><i>/* Return to idle state */</i></b>
<a name="L863" href="source/drivers/net/ethernet/smsc/smc91x.c#L863">863</a>         <a href="ident?i=SMC_SET_MII">SMC_SET_MII</a>(<a href="ident?i=lp">lp</a>, <a href="ident?i=SMC_GET_MII">SMC_GET_MII</a>(<a href="ident?i=lp">lp</a>) &amp; ~(<a href="ident?i=MII_MCLK">MII_MCLK</a>|<a href="ident?i=MII_MDOE">MII_MDOE</a>|<a href="ident?i=MII_MDO">MII_MDO</a>));
<a name="L864" href="source/drivers/net/ethernet/smsc/smc91x.c#L864">864</a> 
<a name="L865" href="source/drivers/net/ethernet/smsc/smc91x.c#L865">865</a>         <a href="ident?i=DBG">DBG</a>(3, <a href="ident?i=dev">dev</a>, <i>"%s: phyaddr=0x%x, phyreg=0x%x, phydata=0x%x\n"</i>,
<a name="L866" href="source/drivers/net/ethernet/smsc/smc91x.c#L866">866</a>             <a href="ident?i=__func__">__func__</a>, <a href="ident?i=phyaddr">phyaddr</a>, phyreg, phydata);
<a name="L867" href="source/drivers/net/ethernet/smsc/smc91x.c#L867">867</a> 
<a name="L868" href="source/drivers/net/ethernet/smsc/smc91x.c#L868">868</a>         <a href="ident?i=SMC_SELECT_BANK">SMC_SELECT_BANK</a>(<a href="ident?i=lp">lp</a>, 2);
<a name="L869" href="source/drivers/net/ethernet/smsc/smc91x.c#L869">869</a> }
<a name="L870" href="source/drivers/net/ethernet/smsc/smc91x.c#L870">870</a> 
<a name="L871" href="source/drivers/net/ethernet/smsc/smc91x.c#L871">871</a> <b><i>/*</i></b>
<a name="L872" href="source/drivers/net/ethernet/smsc/smc91x.c#L872">872</a> <b><i> * Finds and reports the PHY address</i></b>
<a name="L873" href="source/drivers/net/ethernet/smsc/smc91x.c#L873">873</a> <b><i> */</i></b>
<a name="L874" href="source/drivers/net/ethernet/smsc/smc91x.c#L874">874</a> static void <a href="ident?i=smc_phy_detect">smc_phy_detect</a>(struct <a href="ident?i=net_device">net_device</a> *<a href="ident?i=dev">dev</a>)
<a name="L875" href="source/drivers/net/ethernet/smsc/smc91x.c#L875">875</a> {
<a name="L876" href="source/drivers/net/ethernet/smsc/smc91x.c#L876">876</a>         struct <a href="ident?i=smc_local">smc_local</a> *<a href="ident?i=lp">lp</a> = <a href="ident?i=netdev_priv">netdev_priv</a>(<a href="ident?i=dev">dev</a>);
<a name="L877" href="source/drivers/net/ethernet/smsc/smc91x.c#L877">877</a>         int <a href="ident?i=phyaddr">phyaddr</a>;
<a name="L878" href="source/drivers/net/ethernet/smsc/smc91x.c#L878">878</a> 
<a name="L879" href="source/drivers/net/ethernet/smsc/smc91x.c#L879">879</a>         <a href="ident?i=DBG">DBG</a>(2, <a href="ident?i=dev">dev</a>, <i>"%s\n"</i>, <a href="ident?i=__func__">__func__</a>);
<a name="L880" href="source/drivers/net/ethernet/smsc/smc91x.c#L880">880</a> 
<a name="L881" href="source/drivers/net/ethernet/smsc/smc91x.c#L881">881</a>         <a href="ident?i=lp">lp</a>-&gt;phy_type = 0;
<a name="L882" href="source/drivers/net/ethernet/smsc/smc91x.c#L882">882</a> 
<a name="L883" href="source/drivers/net/ethernet/smsc/smc91x.c#L883">883</a>         <b><i>/*</i></b>
<a name="L884" href="source/drivers/net/ethernet/smsc/smc91x.c#L884">884</a> <b><i>         * Scan all 32 PHY addresses if necessary, starting at</i></b>
<a name="L885" href="source/drivers/net/ethernet/smsc/smc91x.c#L885">885</a> <b><i>         * PHY#1 to PHY#31, and then PHY#0 last.</i></b>
<a name="L886" href="source/drivers/net/ethernet/smsc/smc91x.c#L886">886</a> <b><i>         */</i></b>
<a name="L887" href="source/drivers/net/ethernet/smsc/smc91x.c#L887">887</a>         for (<a href="ident?i=phyaddr">phyaddr</a> = 1; <a href="ident?i=phyaddr">phyaddr</a> &lt; 33; ++<a href="ident?i=phyaddr">phyaddr</a>) {
<a name="L888" href="source/drivers/net/ethernet/smsc/smc91x.c#L888">888</a>                 unsigned int <a href="ident?i=id1">id1</a>, <a href="ident?i=id2">id2</a>;
<a name="L889" href="source/drivers/net/ethernet/smsc/smc91x.c#L889">889</a> 
<a name="L890" href="source/drivers/net/ethernet/smsc/smc91x.c#L890">890</a>                 <b><i>/* Read the PHY identifiers */</i></b>
<a name="L891" href="source/drivers/net/ethernet/smsc/smc91x.c#L891">891</a>                 <a href="ident?i=id1">id1</a> = <a href="ident?i=smc_phy_read">smc_phy_read</a>(<a href="ident?i=dev">dev</a>, <a href="ident?i=phyaddr">phyaddr</a> &amp; 31, <a href="ident?i=MII_PHYSID1">MII_PHYSID1</a>);
<a name="L892" href="source/drivers/net/ethernet/smsc/smc91x.c#L892">892</a>                 <a href="ident?i=id2">id2</a> = <a href="ident?i=smc_phy_read">smc_phy_read</a>(<a href="ident?i=dev">dev</a>, <a href="ident?i=phyaddr">phyaddr</a> &amp; 31, <a href="ident?i=MII_PHYSID2">MII_PHYSID2</a>);
<a name="L893" href="source/drivers/net/ethernet/smsc/smc91x.c#L893">893</a> 
<a name="L894" href="source/drivers/net/ethernet/smsc/smc91x.c#L894">894</a>                 <a href="ident?i=DBG">DBG</a>(3, <a href="ident?i=dev">dev</a>, <i>"phy_id1=0x%x, phy_id2=0x%x\n"</i>,
<a name="L895" href="source/drivers/net/ethernet/smsc/smc91x.c#L895">895</a>                     <a href="ident?i=id1">id1</a>, <a href="ident?i=id2">id2</a>);
<a name="L896" href="source/drivers/net/ethernet/smsc/smc91x.c#L896">896</a> 
<a name="L897" href="source/drivers/net/ethernet/smsc/smc91x.c#L897">897</a>                 <b><i>/* Make sure it is a valid identifier */</i></b>
<a name="L898" href="source/drivers/net/ethernet/smsc/smc91x.c#L898">898</a>                 if (<a href="ident?i=id1">id1</a> != 0x0000 &amp;&amp; <a href="ident?i=id1">id1</a> != 0xffff &amp;&amp; <a href="ident?i=id1">id1</a> != 0x8000 &amp;&amp;
<a name="L899" href="source/drivers/net/ethernet/smsc/smc91x.c#L899">899</a>                     <a href="ident?i=id2">id2</a> != 0x0000 &amp;&amp; <a href="ident?i=id2">id2</a> != 0xffff &amp;&amp; <a href="ident?i=id2">id2</a> != 0x8000) {
<a name="L900" href="source/drivers/net/ethernet/smsc/smc91x.c#L900">900</a>                         <b><i>/* Save the PHY's address */</i></b>
<a name="L901" href="source/drivers/net/ethernet/smsc/smc91x.c#L901">901</a>                         <a href="ident?i=lp">lp</a>-&gt;mii.phy_id = <a href="ident?i=phyaddr">phyaddr</a> &amp; 31;
<a name="L902" href="source/drivers/net/ethernet/smsc/smc91x.c#L902">902</a>                         <a href="ident?i=lp">lp</a>-&gt;phy_type = <a href="ident?i=id1">id1</a> &lt;&lt; 16 | <a href="ident?i=id2">id2</a>;
<a name="L903" href="source/drivers/net/ethernet/smsc/smc91x.c#L903">903</a>                         break;
<a name="L904" href="source/drivers/net/ethernet/smsc/smc91x.c#L904">904</a>                 }
<a name="L905" href="source/drivers/net/ethernet/smsc/smc91x.c#L905">905</a>         }
<a name="L906" href="source/drivers/net/ethernet/smsc/smc91x.c#L906">906</a> }
<a name="L907" href="source/drivers/net/ethernet/smsc/smc91x.c#L907">907</a> 
<a name="L908" href="source/drivers/net/ethernet/smsc/smc91x.c#L908">908</a> <b><i>/*</i></b>
<a name="L909" href="source/drivers/net/ethernet/smsc/smc91x.c#L909">909</a> <b><i> * Sets the PHY to a configuration as determined by the user</i></b>
<a name="L910" href="source/drivers/net/ethernet/smsc/smc91x.c#L910">910</a> <b><i> */</i></b>
<a name="L911" href="source/drivers/net/ethernet/smsc/smc91x.c#L911">911</a> static int <a href="ident?i=smc_phy_fixed">smc_phy_fixed</a>(struct <a href="ident?i=net_device">net_device</a> *<a href="ident?i=dev">dev</a>)
<a name="L912" href="source/drivers/net/ethernet/smsc/smc91x.c#L912">912</a> {
<a name="L913" href="source/drivers/net/ethernet/smsc/smc91x.c#L913">913</a>         struct <a href="ident?i=smc_local">smc_local</a> *<a href="ident?i=lp">lp</a> = <a href="ident?i=netdev_priv">netdev_priv</a>(<a href="ident?i=dev">dev</a>);
<a name="L914" href="source/drivers/net/ethernet/smsc/smc91x.c#L914">914</a>         void <a href="ident?i=__iomem">__iomem</a> *<a href="ident?i=ioaddr">ioaddr</a> = <a href="ident?i=lp">lp</a>-&gt;<a href="ident?i=base">base</a>;
<a name="L915" href="source/drivers/net/ethernet/smsc/smc91x.c#L915">915</a>         int <a href="ident?i=phyaddr">phyaddr</a> = <a href="ident?i=lp">lp</a>-&gt;mii.phy_id;
<a name="L916" href="source/drivers/net/ethernet/smsc/smc91x.c#L916">916</a>         int bmcr, cfg1;
<a name="L917" href="source/drivers/net/ethernet/smsc/smc91x.c#L917">917</a> 
<a name="L918" href="source/drivers/net/ethernet/smsc/smc91x.c#L918">918</a>         <a href="ident?i=DBG">DBG</a>(3, <a href="ident?i=dev">dev</a>, <i>"%s\n"</i>, <a href="ident?i=__func__">__func__</a>);
<a name="L919" href="source/drivers/net/ethernet/smsc/smc91x.c#L919">919</a> 
<a name="L920" href="source/drivers/net/ethernet/smsc/smc91x.c#L920">920</a>         <b><i>/* Enter Link Disable state */</i></b>
<a name="L921" href="source/drivers/net/ethernet/smsc/smc91x.c#L921">921</a>         cfg1 = <a href="ident?i=smc_phy_read">smc_phy_read</a>(<a href="ident?i=dev">dev</a>, <a href="ident?i=phyaddr">phyaddr</a>, <a href="ident?i=PHY_CFG1_REG">PHY_CFG1_REG</a>);
<a name="L922" href="source/drivers/net/ethernet/smsc/smc91x.c#L922">922</a>         cfg1 |= <a href="ident?i=PHY_CFG1_LNKDIS">PHY_CFG1_LNKDIS</a>;
<a name="L923" href="source/drivers/net/ethernet/smsc/smc91x.c#L923">923</a>         <a href="ident?i=smc_phy_write">smc_phy_write</a>(<a href="ident?i=dev">dev</a>, <a href="ident?i=phyaddr">phyaddr</a>, <a href="ident?i=PHY_CFG1_REG">PHY_CFG1_REG</a>, cfg1);
<a name="L924" href="source/drivers/net/ethernet/smsc/smc91x.c#L924">924</a> 
<a name="L925" href="source/drivers/net/ethernet/smsc/smc91x.c#L925">925</a>         <b><i>/*</i></b>
<a name="L926" href="source/drivers/net/ethernet/smsc/smc91x.c#L926">926</a> <b><i>         * Set our fixed capabilities</i></b>
<a name="L927" href="source/drivers/net/ethernet/smsc/smc91x.c#L927">927</a> <b><i>         * Disable auto-negotiation</i></b>
<a name="L928" href="source/drivers/net/ethernet/smsc/smc91x.c#L928">928</a> <b><i>         */</i></b>
<a name="L929" href="source/drivers/net/ethernet/smsc/smc91x.c#L929">929</a>         bmcr = 0;
<a name="L930" href="source/drivers/net/ethernet/smsc/smc91x.c#L930">930</a> 
<a name="L931" href="source/drivers/net/ethernet/smsc/smc91x.c#L931">931</a>         if (<a href="ident?i=lp">lp</a>-&gt;ctl_rfduplx)
<a name="L932" href="source/drivers/net/ethernet/smsc/smc91x.c#L932">932</a>                 bmcr |= <a href="ident?i=BMCR_FULLDPLX">BMCR_FULLDPLX</a>;
<a name="L933" href="source/drivers/net/ethernet/smsc/smc91x.c#L933">933</a> 
<a name="L934" href="source/drivers/net/ethernet/smsc/smc91x.c#L934">934</a>         if (<a href="ident?i=lp">lp</a>-&gt;ctl_rspeed == 100)
<a name="L935" href="source/drivers/net/ethernet/smsc/smc91x.c#L935">935</a>                 bmcr |= <a href="ident?i=BMCR_SPEED100">BMCR_SPEED100</a>;
<a name="L936" href="source/drivers/net/ethernet/smsc/smc91x.c#L936">936</a> 
<a name="L937" href="source/drivers/net/ethernet/smsc/smc91x.c#L937">937</a>         <b><i>/* Write our capabilities to the phy control register */</i></b>
<a name="L938" href="source/drivers/net/ethernet/smsc/smc91x.c#L938">938</a>         <a href="ident?i=smc_phy_write">smc_phy_write</a>(<a href="ident?i=dev">dev</a>, <a href="ident?i=phyaddr">phyaddr</a>, <a href="ident?i=MII_BMCR">MII_BMCR</a>, bmcr);
<a name="L939" href="source/drivers/net/ethernet/smsc/smc91x.c#L939">939</a> 
<a name="L940" href="source/drivers/net/ethernet/smsc/smc91x.c#L940">940</a>         <b><i>/* Re-Configure the Receive/Phy Control register */</i></b>
<a name="L941" href="source/drivers/net/ethernet/smsc/smc91x.c#L941">941</a>         <a href="ident?i=SMC_SELECT_BANK">SMC_SELECT_BANK</a>(<a href="ident?i=lp">lp</a>, 0);
<a name="L942" href="source/drivers/net/ethernet/smsc/smc91x.c#L942">942</a>         <a href="ident?i=SMC_SET_RPC">SMC_SET_RPC</a>(<a href="ident?i=lp">lp</a>, <a href="ident?i=lp">lp</a>-&gt;rpc_cur_mode);
<a name="L943" href="source/drivers/net/ethernet/smsc/smc91x.c#L943">943</a>         <a href="ident?i=SMC_SELECT_BANK">SMC_SELECT_BANK</a>(<a href="ident?i=lp">lp</a>, 2);
<a name="L944" href="source/drivers/net/ethernet/smsc/smc91x.c#L944">944</a> 
<a name="L945" href="source/drivers/net/ethernet/smsc/smc91x.c#L945">945</a>         return 1;
<a name="L946" href="source/drivers/net/ethernet/smsc/smc91x.c#L946">946</a> }
<a name="L947" href="source/drivers/net/ethernet/smsc/smc91x.c#L947">947</a> 
<a name="L948" href="source/drivers/net/ethernet/smsc/smc91x.c#L948">948</a> <b><i>/**</i></b>
<a name="L949" href="source/drivers/net/ethernet/smsc/smc91x.c#L949">949</a> <b><i> * smc_phy_reset - reset the phy</i></b>
<a name="L950" href="source/drivers/net/ethernet/smsc/smc91x.c#L950">950</a> <b><i> * @dev: net device</i></b>
<a name="L951" href="source/drivers/net/ethernet/smsc/smc91x.c#L951">951</a> <b><i> * @phy: phy address</i></b>
<a name="L952" href="source/drivers/net/ethernet/smsc/smc91x.c#L952">952</a> <b><i> *</i></b>
<a name="L953" href="source/drivers/net/ethernet/smsc/smc91x.c#L953">953</a> <b><i> * Issue a software reset for the specified PHY and</i></b>
<a name="L954" href="source/drivers/net/ethernet/smsc/smc91x.c#L954">954</a> <b><i> * wait up to 100ms for the reset to complete.  We should</i></b>
<a name="L955" href="source/drivers/net/ethernet/smsc/smc91x.c#L955">955</a> <b><i> * not access the PHY for 50ms after issuing the reset.</i></b>
<a name="L956" href="source/drivers/net/ethernet/smsc/smc91x.c#L956">956</a> <b><i> *</i></b>
<a name="L957" href="source/drivers/net/ethernet/smsc/smc91x.c#L957">957</a> <b><i> * The time to wait appears to be dependent on the PHY.</i></b>
<a name="L958" href="source/drivers/net/ethernet/smsc/smc91x.c#L958">958</a> <b><i> *</i></b>
<a name="L959" href="source/drivers/net/ethernet/smsc/smc91x.c#L959">959</a> <b><i> * Must be called with lp-&gt;lock locked.</i></b>
<a name="L960" href="source/drivers/net/ethernet/smsc/smc91x.c#L960">960</a> <b><i> */</i></b>
<a name="L961" href="source/drivers/net/ethernet/smsc/smc91x.c#L961">961</a> static int <a href="ident?i=smc_phy_reset">smc_phy_reset</a>(struct <a href="ident?i=net_device">net_device</a> *<a href="ident?i=dev">dev</a>, int <a href="ident?i=phy">phy</a>)
<a name="L962" href="source/drivers/net/ethernet/smsc/smc91x.c#L962">962</a> {
<a name="L963" href="source/drivers/net/ethernet/smsc/smc91x.c#L963">963</a>         struct <a href="ident?i=smc_local">smc_local</a> *<a href="ident?i=lp">lp</a> = <a href="ident?i=netdev_priv">netdev_priv</a>(<a href="ident?i=dev">dev</a>);
<a name="L964" href="source/drivers/net/ethernet/smsc/smc91x.c#L964">964</a>         unsigned int bmcr;
<a name="L965" href="source/drivers/net/ethernet/smsc/smc91x.c#L965">965</a>         int <a href="ident?i=timeout">timeout</a>;
<a name="L966" href="source/drivers/net/ethernet/smsc/smc91x.c#L966">966</a> 
<a name="L967" href="source/drivers/net/ethernet/smsc/smc91x.c#L967">967</a>         <a href="ident?i=smc_phy_write">smc_phy_write</a>(<a href="ident?i=dev">dev</a>, <a href="ident?i=phy">phy</a>, <a href="ident?i=MII_BMCR">MII_BMCR</a>, <a href="ident?i=BMCR_RESET">BMCR_RESET</a>);
<a name="L968" href="source/drivers/net/ethernet/smsc/smc91x.c#L968">968</a> 
<a name="L969" href="source/drivers/net/ethernet/smsc/smc91x.c#L969">969</a>         for (<a href="ident?i=timeout">timeout</a> = 2; <a href="ident?i=timeout">timeout</a>; <a href="ident?i=timeout">timeout</a>--) {
<a name="L970" href="source/drivers/net/ethernet/smsc/smc91x.c#L970">970</a>                 <a href="ident?i=spin_unlock_irq">spin_unlock_irq</a>(&amp;<a href="ident?i=lp">lp</a>-&gt;<a href="ident?i=lock">lock</a>);
<a name="L971" href="source/drivers/net/ethernet/smsc/smc91x.c#L971">971</a>                 <a href="ident?i=msleep">msleep</a>(50);
<a name="L972" href="source/drivers/net/ethernet/smsc/smc91x.c#L972">972</a>                 <a href="ident?i=spin_lock_irq">spin_lock_irq</a>(&amp;<a href="ident?i=lp">lp</a>-&gt;<a href="ident?i=lock">lock</a>);
<a name="L973" href="source/drivers/net/ethernet/smsc/smc91x.c#L973">973</a> 
<a name="L974" href="source/drivers/net/ethernet/smsc/smc91x.c#L974">974</a>                 bmcr = <a href="ident?i=smc_phy_read">smc_phy_read</a>(<a href="ident?i=dev">dev</a>, <a href="ident?i=phy">phy</a>, <a href="ident?i=MII_BMCR">MII_BMCR</a>);
<a name="L975" href="source/drivers/net/ethernet/smsc/smc91x.c#L975">975</a>                 if (!(bmcr &amp; <a href="ident?i=BMCR_RESET">BMCR_RESET</a>))
<a name="L976" href="source/drivers/net/ethernet/smsc/smc91x.c#L976">976</a>                         break;
<a name="L977" href="source/drivers/net/ethernet/smsc/smc91x.c#L977">977</a>         }
<a name="L978" href="source/drivers/net/ethernet/smsc/smc91x.c#L978">978</a> 
<a name="L979" href="source/drivers/net/ethernet/smsc/smc91x.c#L979">979</a>         return bmcr &amp; <a href="ident?i=BMCR_RESET">BMCR_RESET</a>;
<a name="L980" href="source/drivers/net/ethernet/smsc/smc91x.c#L980">980</a> }
<a name="L981" href="source/drivers/net/ethernet/smsc/smc91x.c#L981">981</a> 
<a name="L982" href="source/drivers/net/ethernet/smsc/smc91x.c#L982">982</a> <b><i>/**</i></b>
<a name="L983" href="source/drivers/net/ethernet/smsc/smc91x.c#L983">983</a> <b><i> * smc_phy_powerdown - powerdown phy</i></b>
<a name="L984" href="source/drivers/net/ethernet/smsc/smc91x.c#L984">984</a> <b><i> * @dev: net device</i></b>
<a name="L985" href="source/drivers/net/ethernet/smsc/smc91x.c#L985">985</a> <b><i> *</i></b>
<a name="L986" href="source/drivers/net/ethernet/smsc/smc91x.c#L986">986</a> <b><i> * Power down the specified PHY</i></b>
<a name="L987" href="source/drivers/net/ethernet/smsc/smc91x.c#L987">987</a> <b><i> */</i></b>
<a name="L988" href="source/drivers/net/ethernet/smsc/smc91x.c#L988">988</a> static void <a href="ident?i=smc_phy_powerdown">smc_phy_powerdown</a>(struct <a href="ident?i=net_device">net_device</a> *<a href="ident?i=dev">dev</a>)
<a name="L989" href="source/drivers/net/ethernet/smsc/smc91x.c#L989">989</a> {
<a name="L990" href="source/drivers/net/ethernet/smsc/smc91x.c#L990">990</a>         struct <a href="ident?i=smc_local">smc_local</a> *<a href="ident?i=lp">lp</a> = <a href="ident?i=netdev_priv">netdev_priv</a>(<a href="ident?i=dev">dev</a>);
<a name="L991" href="source/drivers/net/ethernet/smsc/smc91x.c#L991">991</a>         unsigned int bmcr;
<a name="L992" href="source/drivers/net/ethernet/smsc/smc91x.c#L992">992</a>         int <a href="ident?i=phy">phy</a> = <a href="ident?i=lp">lp</a>-&gt;mii.phy_id;
<a name="L993" href="source/drivers/net/ethernet/smsc/smc91x.c#L993">993</a> 
<a name="L994" href="source/drivers/net/ethernet/smsc/smc91x.c#L994">994</a>         if (<a href="ident?i=lp">lp</a>-&gt;phy_type == 0)
<a name="L995" href="source/drivers/net/ethernet/smsc/smc91x.c#L995">995</a>                 return;
<a name="L996" href="source/drivers/net/ethernet/smsc/smc91x.c#L996">996</a> 
<a name="L997" href="source/drivers/net/ethernet/smsc/smc91x.c#L997">997</a>         <b><i>/* We need to ensure that no calls to smc_phy_configure are</i></b>
<a name="L998" href="source/drivers/net/ethernet/smsc/smc91x.c#L998">998</a> <b><i>           pending.</i></b>
<a name="L999" href="source/drivers/net/ethernet/smsc/smc91x.c#L999">999</a> <b><i>        */</i></b>
<a name="L1000" href="source/drivers/net/ethernet/smsc/smc91x.c#L1000">1000</a>         <a href="ident?i=cancel_work_sync">cancel_work_sync</a>(&amp;<a href="ident?i=lp">lp</a>-&gt;phy_configure);
<a name="L1001" href="source/drivers/net/ethernet/smsc/smc91x.c#L1001">1001</a> 
<a name="L1002" href="source/drivers/net/ethernet/smsc/smc91x.c#L1002">1002</a>         bmcr = <a href="ident?i=smc_phy_read">smc_phy_read</a>(<a href="ident?i=dev">dev</a>, <a href="ident?i=phy">phy</a>, <a href="ident?i=MII_BMCR">MII_BMCR</a>);
<a name="L1003" href="source/drivers/net/ethernet/smsc/smc91x.c#L1003">1003</a>         <a href="ident?i=smc_phy_write">smc_phy_write</a>(<a href="ident?i=dev">dev</a>, <a href="ident?i=phy">phy</a>, <a href="ident?i=MII_BMCR">MII_BMCR</a>, bmcr | <a href="ident?i=BMCR_PDOWN">BMCR_PDOWN</a>);
<a name="L1004" href="source/drivers/net/ethernet/smsc/smc91x.c#L1004">1004</a> }
<a name="L1005" href="source/drivers/net/ethernet/smsc/smc91x.c#L1005">1005</a> 
<a name="L1006" href="source/drivers/net/ethernet/smsc/smc91x.c#L1006">1006</a> <b><i>/**</i></b>
<a name="L1007" href="source/drivers/net/ethernet/smsc/smc91x.c#L1007">1007</a> <b><i> * smc_phy_check_media - check the media status and adjust TCR</i></b>
<a name="L1008" href="source/drivers/net/ethernet/smsc/smc91x.c#L1008">1008</a> <b><i> * @dev: net device</i></b>
<a name="L1009" href="source/drivers/net/ethernet/smsc/smc91x.c#L1009">1009</a> <b><i> * @init: set true for initialisation</i></b>
<a name="L1010" href="source/drivers/net/ethernet/smsc/smc91x.c#L1010">1010</a> <b><i> *</i></b>
<a name="L1011" href="source/drivers/net/ethernet/smsc/smc91x.c#L1011">1011</a> <b><i> * Select duplex mode depending on negotiation state.  This</i></b>
<a name="L1012" href="source/drivers/net/ethernet/smsc/smc91x.c#L1012">1012</a> <b><i> * also updates our carrier state.</i></b>
<a name="L1013" href="source/drivers/net/ethernet/smsc/smc91x.c#L1013">1013</a> <b><i> */</i></b>
<a name="L1014" href="source/drivers/net/ethernet/smsc/smc91x.c#L1014">1014</a> static void <a href="ident?i=smc_phy_check_media">smc_phy_check_media</a>(struct <a href="ident?i=net_device">net_device</a> *<a href="ident?i=dev">dev</a>, int <a href="ident?i=init">init</a>)
<a name="L1015" href="source/drivers/net/ethernet/smsc/smc91x.c#L1015">1015</a> {
<a name="L1016" href="source/drivers/net/ethernet/smsc/smc91x.c#L1016">1016</a>         struct <a href="ident?i=smc_local">smc_local</a> *<a href="ident?i=lp">lp</a> = <a href="ident?i=netdev_priv">netdev_priv</a>(<a href="ident?i=dev">dev</a>);
<a name="L1017" href="source/drivers/net/ethernet/smsc/smc91x.c#L1017">1017</a>         void <a href="ident?i=__iomem">__iomem</a> *<a href="ident?i=ioaddr">ioaddr</a> = <a href="ident?i=lp">lp</a>-&gt;<a href="ident?i=base">base</a>;
<a name="L1018" href="source/drivers/net/ethernet/smsc/smc91x.c#L1018">1018</a> 
<a name="L1019" href="source/drivers/net/ethernet/smsc/smc91x.c#L1019">1019</a>         if (<a href="ident?i=mii_check_media">mii_check_media</a>(&amp;<a href="ident?i=lp">lp</a>-&gt;mii, <a href="ident?i=netif_msg_link">netif_msg_link</a>(<a href="ident?i=lp">lp</a>), <a href="ident?i=init">init</a>)) {
<a name="L1020" href="source/drivers/net/ethernet/smsc/smc91x.c#L1020">1020</a>                 <b><i>/* duplex state has changed */</i></b>
<a name="L1021" href="source/drivers/net/ethernet/smsc/smc91x.c#L1021">1021</a>                 if (<a href="ident?i=lp">lp</a>-&gt;mii.<a href="ident?i=full_duplex">full_duplex</a>) {
<a name="L1022" href="source/drivers/net/ethernet/smsc/smc91x.c#L1022">1022</a>                         <a href="ident?i=lp">lp</a>-&gt;tcr_cur_mode |= <a href="ident?i=TCR_SWFDUP">TCR_SWFDUP</a>;
<a name="L1023" href="source/drivers/net/ethernet/smsc/smc91x.c#L1023">1023</a>                 } else {
<a name="L1024" href="source/drivers/net/ethernet/smsc/smc91x.c#L1024">1024</a>                         <a href="ident?i=lp">lp</a>-&gt;tcr_cur_mode &amp;= ~TCR_SWFDUP;
<a name="L1025" href="source/drivers/net/ethernet/smsc/smc91x.c#L1025">1025</a>                 }
<a name="L1026" href="source/drivers/net/ethernet/smsc/smc91x.c#L1026">1026</a> 
<a name="L1027" href="source/drivers/net/ethernet/smsc/smc91x.c#L1027">1027</a>                 <a href="ident?i=SMC_SELECT_BANK">SMC_SELECT_BANK</a>(<a href="ident?i=lp">lp</a>, 0);
<a name="L1028" href="source/drivers/net/ethernet/smsc/smc91x.c#L1028">1028</a>                 <a href="ident?i=SMC_SET_TCR">SMC_SET_TCR</a>(<a href="ident?i=lp">lp</a>, <a href="ident?i=lp">lp</a>-&gt;tcr_cur_mode);
<a name="L1029" href="source/drivers/net/ethernet/smsc/smc91x.c#L1029">1029</a>         }
<a name="L1030" href="source/drivers/net/ethernet/smsc/smc91x.c#L1030">1030</a> }
<a name="L1031" href="source/drivers/net/ethernet/smsc/smc91x.c#L1031">1031</a> 
<a name="L1032" href="source/drivers/net/ethernet/smsc/smc91x.c#L1032">1032</a> <b><i>/*</i></b>
<a name="L1033" href="source/drivers/net/ethernet/smsc/smc91x.c#L1033">1033</a> <b><i> * Configures the specified PHY through the MII management interface</i></b>
<a name="L1034" href="source/drivers/net/ethernet/smsc/smc91x.c#L1034">1034</a> <b><i> * using Autonegotiation.</i></b>
<a name="L1035" href="source/drivers/net/ethernet/smsc/smc91x.c#L1035">1035</a> <b><i> * Calls smc_phy_fixed() if the user has requested a certain config.</i></b>
<a name="L1036" href="source/drivers/net/ethernet/smsc/smc91x.c#L1036">1036</a> <b><i> * If RPC ANEG bit is set, the media selection is dependent purely on</i></b>
<a name="L1037" href="source/drivers/net/ethernet/smsc/smc91x.c#L1037">1037</a> <b><i> * the selection by the MII (either in the MII BMCR reg or the result</i></b>
<a name="L1038" href="source/drivers/net/ethernet/smsc/smc91x.c#L1038">1038</a> <b><i> * of autonegotiation.)  If the RPC ANEG bit is cleared, the selection</i></b>
<a name="L1039" href="source/drivers/net/ethernet/smsc/smc91x.c#L1039">1039</a> <b><i> * is controlled by the RPC SPEED and RPC DPLX bits.</i></b>
<a name="L1040" href="source/drivers/net/ethernet/smsc/smc91x.c#L1040">1040</a> <b><i> */</i></b>
<a name="L1041" href="source/drivers/net/ethernet/smsc/smc91x.c#L1041">1041</a> static void <a href="ident?i=smc_phy_configure">smc_phy_configure</a>(struct <a href="ident?i=work_struct">work_struct</a> *<a href="ident?i=work">work</a>)
<a name="L1042" href="source/drivers/net/ethernet/smsc/smc91x.c#L1042">1042</a> {
<a name="L1043" href="source/drivers/net/ethernet/smsc/smc91x.c#L1043">1043</a>         struct <a href="ident?i=smc_local">smc_local</a> *<a href="ident?i=lp">lp</a> =
<a name="L1044" href="source/drivers/net/ethernet/smsc/smc91x.c#L1044">1044</a>                 <a href="ident?i=container_of">container_of</a>(<a href="ident?i=work">work</a>, struct <a href="ident?i=smc_local">smc_local</a>, phy_configure);
<a name="L1045" href="source/drivers/net/ethernet/smsc/smc91x.c#L1045">1045</a>         struct <a href="ident?i=net_device">net_device</a> *<a href="ident?i=dev">dev</a> = <a href="ident?i=lp">lp</a>-&gt;<a href="ident?i=dev">dev</a>;
<a name="L1046" href="source/drivers/net/ethernet/smsc/smc91x.c#L1046">1046</a>         void <a href="ident?i=__iomem">__iomem</a> *<a href="ident?i=ioaddr">ioaddr</a> = <a href="ident?i=lp">lp</a>-&gt;<a href="ident?i=base">base</a>;
<a name="L1047" href="source/drivers/net/ethernet/smsc/smc91x.c#L1047">1047</a>         int <a href="ident?i=phyaddr">phyaddr</a> = <a href="ident?i=lp">lp</a>-&gt;mii.phy_id;
<a name="L1048" href="source/drivers/net/ethernet/smsc/smc91x.c#L1048">1048</a>         int my_phy_caps; <b><i>/* My PHY capabilities */</i></b>
<a name="L1049" href="source/drivers/net/ethernet/smsc/smc91x.c#L1049">1049</a>         int my_ad_caps; <b><i>/* My Advertised capabilities */</i></b>
<a name="L1050" href="source/drivers/net/ethernet/smsc/smc91x.c#L1050">1050</a>         int <a href="ident?i=status">status</a>;
<a name="L1051" href="source/drivers/net/ethernet/smsc/smc91x.c#L1051">1051</a> 
<a name="L1052" href="source/drivers/net/ethernet/smsc/smc91x.c#L1052">1052</a>         <a href="ident?i=DBG">DBG</a>(3, <a href="ident?i=dev">dev</a>, <i>"smc_program_phy()\n"</i>);
<a name="L1053" href="source/drivers/net/ethernet/smsc/smc91x.c#L1053">1053</a> 
<a name="L1054" href="source/drivers/net/ethernet/smsc/smc91x.c#L1054">1054</a>         <a href="ident?i=spin_lock_irq">spin_lock_irq</a>(&amp;<a href="ident?i=lp">lp</a>-&gt;<a href="ident?i=lock">lock</a>);
<a name="L1055" href="source/drivers/net/ethernet/smsc/smc91x.c#L1055">1055</a> 
<a name="L1056" href="source/drivers/net/ethernet/smsc/smc91x.c#L1056">1056</a>         <b><i>/*</i></b>
<a name="L1057" href="source/drivers/net/ethernet/smsc/smc91x.c#L1057">1057</a> <b><i>         * We should not be called if phy_type is zero.</i></b>
<a name="L1058" href="source/drivers/net/ethernet/smsc/smc91x.c#L1058">1058</a> <b><i>         */</i></b>
<a name="L1059" href="source/drivers/net/ethernet/smsc/smc91x.c#L1059">1059</a>         if (<a href="ident?i=lp">lp</a>-&gt;phy_type == 0)
<a name="L1060" href="source/drivers/net/ethernet/smsc/smc91x.c#L1060">1060</a>                 goto smc_phy_configure_exit;
<a name="L1061" href="source/drivers/net/ethernet/smsc/smc91x.c#L1061">1061</a> 
<a name="L1062" href="source/drivers/net/ethernet/smsc/smc91x.c#L1062">1062</a>         if (<a href="ident?i=smc_phy_reset">smc_phy_reset</a>(<a href="ident?i=dev">dev</a>, <a href="ident?i=phyaddr">phyaddr</a>)) {
<a name="L1063" href="source/drivers/net/ethernet/smsc/smc91x.c#L1063">1063</a>                 <a href="ident?i=netdev_info">netdev_info</a>(<a href="ident?i=dev">dev</a>, <i>"PHY reset timed out\n"</i>);
<a name="L1064" href="source/drivers/net/ethernet/smsc/smc91x.c#L1064">1064</a>                 goto smc_phy_configure_exit;
<a name="L1065" href="source/drivers/net/ethernet/smsc/smc91x.c#L1065">1065</a>         }
<a name="L1066" href="source/drivers/net/ethernet/smsc/smc91x.c#L1066">1066</a> 
<a name="L1067" href="source/drivers/net/ethernet/smsc/smc91x.c#L1067">1067</a>         <b><i>/*</i></b>
<a name="L1068" href="source/drivers/net/ethernet/smsc/smc91x.c#L1068">1068</a> <b><i>         * Enable PHY Interrupts (for register 18)</i></b>
<a name="L1069" href="source/drivers/net/ethernet/smsc/smc91x.c#L1069">1069</a> <b><i>         * Interrupts listed here are disabled</i></b>
<a name="L1070" href="source/drivers/net/ethernet/smsc/smc91x.c#L1070">1070</a> <b><i>         */</i></b>
<a name="L1071" href="source/drivers/net/ethernet/smsc/smc91x.c#L1071">1071</a>         <a href="ident?i=smc_phy_write">smc_phy_write</a>(<a href="ident?i=dev">dev</a>, <a href="ident?i=phyaddr">phyaddr</a>, <a href="ident?i=PHY_MASK_REG">PHY_MASK_REG</a>,
<a name="L1072" href="source/drivers/net/ethernet/smsc/smc91x.c#L1072">1072</a>                 <a href="ident?i=PHY_INT_LOSSSYNC">PHY_INT_LOSSSYNC</a> | <a href="ident?i=PHY_INT_CWRD">PHY_INT_CWRD</a> | <a href="ident?i=PHY_INT_SSD">PHY_INT_SSD</a> |
<a name="L1073" href="source/drivers/net/ethernet/smsc/smc91x.c#L1073">1073</a>                 <a href="ident?i=PHY_INT_ESD">PHY_INT_ESD</a> | <a href="ident?i=PHY_INT_RPOL">PHY_INT_RPOL</a> | <a href="ident?i=PHY_INT_JAB">PHY_INT_JAB</a> |
<a name="L1074" href="source/drivers/net/ethernet/smsc/smc91x.c#L1074">1074</a>                 <a href="ident?i=PHY_INT_SPDDET">PHY_INT_SPDDET</a> | <a href="ident?i=PHY_INT_DPLXDET">PHY_INT_DPLXDET</a>);
<a name="L1075" href="source/drivers/net/ethernet/smsc/smc91x.c#L1075">1075</a> 
<a name="L1076" href="source/drivers/net/ethernet/smsc/smc91x.c#L1076">1076</a>         <b><i>/* Configure the Receive/Phy Control register */</i></b>
<a name="L1077" href="source/drivers/net/ethernet/smsc/smc91x.c#L1077">1077</a>         <a href="ident?i=SMC_SELECT_BANK">SMC_SELECT_BANK</a>(<a href="ident?i=lp">lp</a>, 0);
<a name="L1078" href="source/drivers/net/ethernet/smsc/smc91x.c#L1078">1078</a>         <a href="ident?i=SMC_SET_RPC">SMC_SET_RPC</a>(<a href="ident?i=lp">lp</a>, <a href="ident?i=lp">lp</a>-&gt;rpc_cur_mode);
<a name="L1079" href="source/drivers/net/ethernet/smsc/smc91x.c#L1079">1079</a> 
<a name="L1080" href="source/drivers/net/ethernet/smsc/smc91x.c#L1080">1080</a>         <b><i>/* If the user requested no auto neg, then go set his request */</i></b>
<a name="L1081" href="source/drivers/net/ethernet/smsc/smc91x.c#L1081">1081</a>         if (<a href="ident?i=lp">lp</a>-&gt;mii.force_media) {
<a name="L1082" href="source/drivers/net/ethernet/smsc/smc91x.c#L1082">1082</a>                 <a href="ident?i=smc_phy_fixed">smc_phy_fixed</a>(<a href="ident?i=dev">dev</a>);
<a name="L1083" href="source/drivers/net/ethernet/smsc/smc91x.c#L1083">1083</a>                 goto smc_phy_configure_exit;
<a name="L1084" href="source/drivers/net/ethernet/smsc/smc91x.c#L1084">1084</a>         }
<a name="L1085" href="source/drivers/net/ethernet/smsc/smc91x.c#L1085">1085</a> 
<a name="L1086" href="source/drivers/net/ethernet/smsc/smc91x.c#L1086">1086</a>         <b><i>/* Copy our capabilities from MII_BMSR to MII_ADVERTISE */</i></b>
<a name="L1087" href="source/drivers/net/ethernet/smsc/smc91x.c#L1087">1087</a>         my_phy_caps = <a href="ident?i=smc_phy_read">smc_phy_read</a>(<a href="ident?i=dev">dev</a>, <a href="ident?i=phyaddr">phyaddr</a>, <a href="ident?i=MII_BMSR">MII_BMSR</a>);
<a name="L1088" href="source/drivers/net/ethernet/smsc/smc91x.c#L1088">1088</a> 
<a name="L1089" href="source/drivers/net/ethernet/smsc/smc91x.c#L1089">1089</a>         if (!(my_phy_caps &amp; <a href="ident?i=BMSR_ANEGCAPABLE">BMSR_ANEGCAPABLE</a>)) {
<a name="L1090" href="source/drivers/net/ethernet/smsc/smc91x.c#L1090">1090</a>                 <a href="ident?i=netdev_info">netdev_info</a>(<a href="ident?i=dev">dev</a>, <i>"Auto negotiation NOT supported\n"</i>);
<a name="L1091" href="source/drivers/net/ethernet/smsc/smc91x.c#L1091">1091</a>                 <a href="ident?i=smc_phy_fixed">smc_phy_fixed</a>(<a href="ident?i=dev">dev</a>);
<a name="L1092" href="source/drivers/net/ethernet/smsc/smc91x.c#L1092">1092</a>                 goto smc_phy_configure_exit;
<a name="L1093" href="source/drivers/net/ethernet/smsc/smc91x.c#L1093">1093</a>         }
<a name="L1094" href="source/drivers/net/ethernet/smsc/smc91x.c#L1094">1094</a> 
<a name="L1095" href="source/drivers/net/ethernet/smsc/smc91x.c#L1095">1095</a>         my_ad_caps = <a href="ident?i=ADVERTISE_CSMA">ADVERTISE_CSMA</a>; <b><i>/* I am CSMA capable */</i></b>
<a name="L1096" href="source/drivers/net/ethernet/smsc/smc91x.c#L1096">1096</a> 
<a name="L1097" href="source/drivers/net/ethernet/smsc/smc91x.c#L1097">1097</a>         if (my_phy_caps &amp; <a href="ident?i=BMSR_100BASE4">BMSR_100BASE4</a>)
<a name="L1098" href="source/drivers/net/ethernet/smsc/smc91x.c#L1098">1098</a>                 my_ad_caps |= <a href="ident?i=ADVERTISE_100BASE4">ADVERTISE_100BASE4</a>;
<a name="L1099" href="source/drivers/net/ethernet/smsc/smc91x.c#L1099">1099</a>         if (my_phy_caps &amp; <a href="ident?i=BMSR_100FULL">BMSR_100FULL</a>)
<a name="L1100" href="source/drivers/net/ethernet/smsc/smc91x.c#L1100">1100</a>                 my_ad_caps |= <a href="ident?i=ADVERTISE_100FULL">ADVERTISE_100FULL</a>;
<a name="L1101" href="source/drivers/net/ethernet/smsc/smc91x.c#L1101">1101</a>         if (my_phy_caps &amp; <a href="ident?i=BMSR_100HALF">BMSR_100HALF</a>)
<a name="L1102" href="source/drivers/net/ethernet/smsc/smc91x.c#L1102">1102</a>                 my_ad_caps |= <a href="ident?i=ADVERTISE_100HALF">ADVERTISE_100HALF</a>;
<a name="L1103" href="source/drivers/net/ethernet/smsc/smc91x.c#L1103">1103</a>         if (my_phy_caps &amp; <a href="ident?i=BMSR_10FULL">BMSR_10FULL</a>)
<a name="L1104" href="source/drivers/net/ethernet/smsc/smc91x.c#L1104">1104</a>                 my_ad_caps |= <a href="ident?i=ADVERTISE_10FULL">ADVERTISE_10FULL</a>;
<a name="L1105" href="source/drivers/net/ethernet/smsc/smc91x.c#L1105">1105</a>         if (my_phy_caps &amp; <a href="ident?i=BMSR_10HALF">BMSR_10HALF</a>)
<a name="L1106" href="source/drivers/net/ethernet/smsc/smc91x.c#L1106">1106</a>                 my_ad_caps |= <a href="ident?i=ADVERTISE_10HALF">ADVERTISE_10HALF</a>;
<a name="L1107" href="source/drivers/net/ethernet/smsc/smc91x.c#L1107">1107</a> 
<a name="L1108" href="source/drivers/net/ethernet/smsc/smc91x.c#L1108">1108</a>         <b><i>/* Disable capabilities not selected by our user */</i></b>
<a name="L1109" href="source/drivers/net/ethernet/smsc/smc91x.c#L1109">1109</a>         if (<a href="ident?i=lp">lp</a>-&gt;ctl_rspeed != 100)
<a name="L1110" href="source/drivers/net/ethernet/smsc/smc91x.c#L1110">1110</a>                 my_ad_caps &amp;= ~(<a href="ident?i=ADVERTISE_100BASE4">ADVERTISE_100BASE4</a>|<a href="ident?i=ADVERTISE_100FULL">ADVERTISE_100FULL</a>|<a href="ident?i=ADVERTISE_100HALF">ADVERTISE_100HALF</a>);
<a name="L1111" href="source/drivers/net/ethernet/smsc/smc91x.c#L1111">1111</a> 
<a name="L1112" href="source/drivers/net/ethernet/smsc/smc91x.c#L1112">1112</a>         if (!<a href="ident?i=lp">lp</a>-&gt;ctl_rfduplx)
<a name="L1113" href="source/drivers/net/ethernet/smsc/smc91x.c#L1113">1113</a>                 my_ad_caps &amp;= ~(<a href="ident?i=ADVERTISE_100FULL">ADVERTISE_100FULL</a>|<a href="ident?i=ADVERTISE_10FULL">ADVERTISE_10FULL</a>);
<a name="L1114" href="source/drivers/net/ethernet/smsc/smc91x.c#L1114">1114</a> 
<a name="L1115" href="source/drivers/net/ethernet/smsc/smc91x.c#L1115">1115</a>         <b><i>/* Update our Auto-Neg Advertisement Register */</i></b>
<a name="L1116" href="source/drivers/net/ethernet/smsc/smc91x.c#L1116">1116</a>         <a href="ident?i=smc_phy_write">smc_phy_write</a>(<a href="ident?i=dev">dev</a>, <a href="ident?i=phyaddr">phyaddr</a>, <a href="ident?i=MII_ADVERTISE">MII_ADVERTISE</a>, my_ad_caps);
<a name="L1117" href="source/drivers/net/ethernet/smsc/smc91x.c#L1117">1117</a>         <a href="ident?i=lp">lp</a>-&gt;mii.advertising = my_ad_caps;
<a name="L1118" href="source/drivers/net/ethernet/smsc/smc91x.c#L1118">1118</a> 
<a name="L1119" href="source/drivers/net/ethernet/smsc/smc91x.c#L1119">1119</a>         <b><i>/*</i></b>
<a name="L1120" href="source/drivers/net/ethernet/smsc/smc91x.c#L1120">1120</a> <b><i>         * Read the register back.  Without this, it appears that when</i></b>
<a name="L1121" href="source/drivers/net/ethernet/smsc/smc91x.c#L1121">1121</a> <b><i>         * auto-negotiation is restarted, sometimes it isn't ready and</i></b>
<a name="L1122" href="source/drivers/net/ethernet/smsc/smc91x.c#L1122">1122</a> <b><i>         * the link does not come up.</i></b>
<a name="L1123" href="source/drivers/net/ethernet/smsc/smc91x.c#L1123">1123</a> <b><i>         */</i></b>
<a name="L1124" href="source/drivers/net/ethernet/smsc/smc91x.c#L1124">1124</a>         <a href="ident?i=status">status</a> = <a href="ident?i=smc_phy_read">smc_phy_read</a>(<a href="ident?i=dev">dev</a>, <a href="ident?i=phyaddr">phyaddr</a>, <a href="ident?i=MII_ADVERTISE">MII_ADVERTISE</a>);
<a name="L1125" href="source/drivers/net/ethernet/smsc/smc91x.c#L1125">1125</a> 
<a name="L1126" href="source/drivers/net/ethernet/smsc/smc91x.c#L1126">1126</a>         <a href="ident?i=DBG">DBG</a>(2, <a href="ident?i=dev">dev</a>, <i>"phy caps=%x\n"</i>, my_phy_caps);
<a name="L1127" href="source/drivers/net/ethernet/smsc/smc91x.c#L1127">1127</a>         <a href="ident?i=DBG">DBG</a>(2, <a href="ident?i=dev">dev</a>, <i>"phy advertised caps=%x\n"</i>, my_ad_caps);
<a name="L1128" href="source/drivers/net/ethernet/smsc/smc91x.c#L1128">1128</a> 
<a name="L1129" href="source/drivers/net/ethernet/smsc/smc91x.c#L1129">1129</a>         <b><i>/* Restart auto-negotiation process in order to advertise my caps */</i></b>
<a name="L1130" href="source/drivers/net/ethernet/smsc/smc91x.c#L1130">1130</a>         <a href="ident?i=smc_phy_write">smc_phy_write</a>(<a href="ident?i=dev">dev</a>, <a href="ident?i=phyaddr">phyaddr</a>, <a href="ident?i=MII_BMCR">MII_BMCR</a>, <a href="ident?i=BMCR_ANENABLE">BMCR_ANENABLE</a> | <a href="ident?i=BMCR_ANRESTART">BMCR_ANRESTART</a>);
<a name="L1131" href="source/drivers/net/ethernet/smsc/smc91x.c#L1131">1131</a> 
<a name="L1132" href="source/drivers/net/ethernet/smsc/smc91x.c#L1132">1132</a>         <a href="ident?i=smc_phy_check_media">smc_phy_check_media</a>(<a href="ident?i=dev">dev</a>, 1);
<a name="L1133" href="source/drivers/net/ethernet/smsc/smc91x.c#L1133">1133</a> 
<a name="L1134" href="source/drivers/net/ethernet/smsc/smc91x.c#L1134">1134</a> smc_phy_configure_exit:
<a name="L1135" href="source/drivers/net/ethernet/smsc/smc91x.c#L1135">1135</a>         <a href="ident?i=SMC_SELECT_BANK">SMC_SELECT_BANK</a>(<a href="ident?i=lp">lp</a>, 2);
<a name="L1136" href="source/drivers/net/ethernet/smsc/smc91x.c#L1136">1136</a>         <a href="ident?i=spin_unlock_irq">spin_unlock_irq</a>(&amp;<a href="ident?i=lp">lp</a>-&gt;<a href="ident?i=lock">lock</a>);
<a name="L1137" href="source/drivers/net/ethernet/smsc/smc91x.c#L1137">1137</a> }
<a name="L1138" href="source/drivers/net/ethernet/smsc/smc91x.c#L1138">1138</a> 
<a name="L1139" href="source/drivers/net/ethernet/smsc/smc91x.c#L1139">1139</a> <b><i>/*</i></b>
<a name="L1140" href="source/drivers/net/ethernet/smsc/smc91x.c#L1140">1140</a> <b><i> * smc_phy_interrupt</i></b>
<a name="L1141" href="source/drivers/net/ethernet/smsc/smc91x.c#L1141">1141</a> <b><i> *</i></b>
<a name="L1142" href="source/drivers/net/ethernet/smsc/smc91x.c#L1142">1142</a> <b><i> * Purpose:  Handle interrupts relating to PHY register 18. This is</i></b>
<a name="L1143" href="source/drivers/net/ethernet/smsc/smc91x.c#L1143">1143</a> <b><i> *  called from the "hard" interrupt handler under our private spinlock.</i></b>
<a name="L1144" href="source/drivers/net/ethernet/smsc/smc91x.c#L1144">1144</a> <b><i> */</i></b>
<a name="L1145" href="source/drivers/net/ethernet/smsc/smc91x.c#L1145">1145</a> static void <a href="ident?i=smc_phy_interrupt">smc_phy_interrupt</a>(struct <a href="ident?i=net_device">net_device</a> *<a href="ident?i=dev">dev</a>)
<a name="L1146" href="source/drivers/net/ethernet/smsc/smc91x.c#L1146">1146</a> {
<a name="L1147" href="source/drivers/net/ethernet/smsc/smc91x.c#L1147">1147</a>         struct <a href="ident?i=smc_local">smc_local</a> *<a href="ident?i=lp">lp</a> = <a href="ident?i=netdev_priv">netdev_priv</a>(<a href="ident?i=dev">dev</a>);
<a name="L1148" href="source/drivers/net/ethernet/smsc/smc91x.c#L1148">1148</a>         int <a href="ident?i=phyaddr">phyaddr</a> = <a href="ident?i=lp">lp</a>-&gt;mii.phy_id;
<a name="L1149" href="source/drivers/net/ethernet/smsc/smc91x.c#L1149">1149</a>         int phy18;
<a name="L1150" href="source/drivers/net/ethernet/smsc/smc91x.c#L1150">1150</a> 
<a name="L1151" href="source/drivers/net/ethernet/smsc/smc91x.c#L1151">1151</a>         <a href="ident?i=DBG">DBG</a>(2, <a href="ident?i=dev">dev</a>, <i>"%s\n"</i>, <a href="ident?i=__func__">__func__</a>);
<a name="L1152" href="source/drivers/net/ethernet/smsc/smc91x.c#L1152">1152</a> 
<a name="L1153" href="source/drivers/net/ethernet/smsc/smc91x.c#L1153">1153</a>         if (<a href="ident?i=lp">lp</a>-&gt;phy_type == 0)
<a name="L1154" href="source/drivers/net/ethernet/smsc/smc91x.c#L1154">1154</a>                 return;
<a name="L1155" href="source/drivers/net/ethernet/smsc/smc91x.c#L1155">1155</a> 
<a name="L1156" href="source/drivers/net/ethernet/smsc/smc91x.c#L1156">1156</a>         for(;;) {
<a name="L1157" href="source/drivers/net/ethernet/smsc/smc91x.c#L1157">1157</a>                 <a href="ident?i=smc_phy_check_media">smc_phy_check_media</a>(<a href="ident?i=dev">dev</a>, 0);
<a name="L1158" href="source/drivers/net/ethernet/smsc/smc91x.c#L1158">1158</a> 
<a name="L1159" href="source/drivers/net/ethernet/smsc/smc91x.c#L1159">1159</a>                 <b><i>/* Read PHY Register 18, Status Output */</i></b>
<a name="L1160" href="source/drivers/net/ethernet/smsc/smc91x.c#L1160">1160</a>                 phy18 = <a href="ident?i=smc_phy_read">smc_phy_read</a>(<a href="ident?i=dev">dev</a>, <a href="ident?i=phyaddr">phyaddr</a>, <a href="ident?i=PHY_INT_REG">PHY_INT_REG</a>);
<a name="L1161" href="source/drivers/net/ethernet/smsc/smc91x.c#L1161">1161</a>                 if ((phy18 &amp; <a href="ident?i=PHY_INT_INT">PHY_INT_INT</a>) == 0)
<a name="L1162" href="source/drivers/net/ethernet/smsc/smc91x.c#L1162">1162</a>                         break;
<a name="L1163" href="source/drivers/net/ethernet/smsc/smc91x.c#L1163">1163</a>         }
<a name="L1164" href="source/drivers/net/ethernet/smsc/smc91x.c#L1164">1164</a> }
<a name="L1165" href="source/drivers/net/ethernet/smsc/smc91x.c#L1165">1165</a> 
<a name="L1166" href="source/drivers/net/ethernet/smsc/smc91x.c#L1166">1166</a> <b><i>/*--- END PHY CONTROL AND CONFIGURATION-------------------------------------*/</i></b>
<a name="L1167" href="source/drivers/net/ethernet/smsc/smc91x.c#L1167">1167</a> 
<a name="L1168" href="source/drivers/net/ethernet/smsc/smc91x.c#L1168">1168</a> static void <a href="ident?i=smc_10bt_check_media">smc_10bt_check_media</a>(struct <a href="ident?i=net_device">net_device</a> *<a href="ident?i=dev">dev</a>, int <a href="ident?i=init">init</a>)
<a name="L1169" href="source/drivers/net/ethernet/smsc/smc91x.c#L1169">1169</a> {
<a name="L1170" href="source/drivers/net/ethernet/smsc/smc91x.c#L1170">1170</a>         struct <a href="ident?i=smc_local">smc_local</a> *<a href="ident?i=lp">lp</a> = <a href="ident?i=netdev_priv">netdev_priv</a>(<a href="ident?i=dev">dev</a>);
<a name="L1171" href="source/drivers/net/ethernet/smsc/smc91x.c#L1171">1171</a>         void <a href="ident?i=__iomem">__iomem</a> *<a href="ident?i=ioaddr">ioaddr</a> = <a href="ident?i=lp">lp</a>-&gt;<a href="ident?i=base">base</a>;
<a name="L1172" href="source/drivers/net/ethernet/smsc/smc91x.c#L1172">1172</a>         unsigned int old_carrier, new_carrier;
<a name="L1173" href="source/drivers/net/ethernet/smsc/smc91x.c#L1173">1173</a> 
<a name="L1174" href="source/drivers/net/ethernet/smsc/smc91x.c#L1174">1174</a>         old_carrier = <a href="ident?i=netif_carrier_ok">netif_carrier_ok</a>(<a href="ident?i=dev">dev</a>) ? 1 : 0;
<a name="L1175" href="source/drivers/net/ethernet/smsc/smc91x.c#L1175">1175</a> 
<a name="L1176" href="source/drivers/net/ethernet/smsc/smc91x.c#L1176">1176</a>         <a href="ident?i=SMC_SELECT_BANK">SMC_SELECT_BANK</a>(<a href="ident?i=lp">lp</a>, 0);
<a name="L1177" href="source/drivers/net/ethernet/smsc/smc91x.c#L1177">1177</a>         new_carrier = (<a href="ident?i=SMC_GET_EPH_STATUS">SMC_GET_EPH_STATUS</a>(<a href="ident?i=lp">lp</a>) &amp; <a href="ident?i=ES_LINK_OK">ES_LINK_OK</a>) ? 1 : 0;
<a name="L1178" href="source/drivers/net/ethernet/smsc/smc91x.c#L1178">1178</a>         <a href="ident?i=SMC_SELECT_BANK">SMC_SELECT_BANK</a>(<a href="ident?i=lp">lp</a>, 2);
<a name="L1179" href="source/drivers/net/ethernet/smsc/smc91x.c#L1179">1179</a> 
<a name="L1180" href="source/drivers/net/ethernet/smsc/smc91x.c#L1180">1180</a>         if (<a href="ident?i=init">init</a> || (old_carrier != new_carrier)) {
<a name="L1181" href="source/drivers/net/ethernet/smsc/smc91x.c#L1181">1181</a>                 if (!new_carrier) {
<a name="L1182" href="source/drivers/net/ethernet/smsc/smc91x.c#L1182">1182</a>                         <a href="ident?i=netif_carrier_off">netif_carrier_off</a>(<a href="ident?i=dev">dev</a>);
<a name="L1183" href="source/drivers/net/ethernet/smsc/smc91x.c#L1183">1183</a>                 } else {
<a name="L1184" href="source/drivers/net/ethernet/smsc/smc91x.c#L1184">1184</a>                         <a href="ident?i=netif_carrier_on">netif_carrier_on</a>(<a href="ident?i=dev">dev</a>);
<a name="L1185" href="source/drivers/net/ethernet/smsc/smc91x.c#L1185">1185</a>                 }
<a name="L1186" href="source/drivers/net/ethernet/smsc/smc91x.c#L1186">1186</a>                 if (<a href="ident?i=netif_msg_link">netif_msg_link</a>(<a href="ident?i=lp">lp</a>))
<a name="L1187" href="source/drivers/net/ethernet/smsc/smc91x.c#L1187">1187</a>                         <a href="ident?i=netdev_info">netdev_info</a>(<a href="ident?i=dev">dev</a>, <i>"link %s\n"</i>,
<a name="L1188" href="source/drivers/net/ethernet/smsc/smc91x.c#L1188">1188</a>                                     new_carrier ? <i>"up"</i> : <i>"down"</i>);
<a name="L1189" href="source/drivers/net/ethernet/smsc/smc91x.c#L1189">1189</a>         }
<a name="L1190" href="source/drivers/net/ethernet/smsc/smc91x.c#L1190">1190</a> }
<a name="L1191" href="source/drivers/net/ethernet/smsc/smc91x.c#L1191">1191</a> 
<a name="L1192" href="source/drivers/net/ethernet/smsc/smc91x.c#L1192">1192</a> static void <a href="ident?i=smc_eph_interrupt">smc_eph_interrupt</a>(struct <a href="ident?i=net_device">net_device</a> *<a href="ident?i=dev">dev</a>)
<a name="L1193" href="source/drivers/net/ethernet/smsc/smc91x.c#L1193">1193</a> {
<a name="L1194" href="source/drivers/net/ethernet/smsc/smc91x.c#L1194">1194</a>         struct <a href="ident?i=smc_local">smc_local</a> *<a href="ident?i=lp">lp</a> = <a href="ident?i=netdev_priv">netdev_priv</a>(<a href="ident?i=dev">dev</a>);
<a name="L1195" href="source/drivers/net/ethernet/smsc/smc91x.c#L1195">1195</a>         void <a href="ident?i=__iomem">__iomem</a> *<a href="ident?i=ioaddr">ioaddr</a> = <a href="ident?i=lp">lp</a>-&gt;<a href="ident?i=base">base</a>;
<a name="L1196" href="source/drivers/net/ethernet/smsc/smc91x.c#L1196">1196</a>         unsigned int <a href="ident?i=ctl">ctl</a>;
<a name="L1197" href="source/drivers/net/ethernet/smsc/smc91x.c#L1197">1197</a> 
<a name="L1198" href="source/drivers/net/ethernet/smsc/smc91x.c#L1198">1198</a>         <a href="ident?i=smc_10bt_check_media">smc_10bt_check_media</a>(<a href="ident?i=dev">dev</a>, 0);
<a name="L1199" href="source/drivers/net/ethernet/smsc/smc91x.c#L1199">1199</a> 
<a name="L1200" href="source/drivers/net/ethernet/smsc/smc91x.c#L1200">1200</a>         <a href="ident?i=SMC_SELECT_BANK">SMC_SELECT_BANK</a>(<a href="ident?i=lp">lp</a>, 1);
<a name="L1201" href="source/drivers/net/ethernet/smsc/smc91x.c#L1201">1201</a>         <a href="ident?i=ctl">ctl</a> = <a href="ident?i=SMC_GET_CTL">SMC_GET_CTL</a>(<a href="ident?i=lp">lp</a>);
<a name="L1202" href="source/drivers/net/ethernet/smsc/smc91x.c#L1202">1202</a>         <a href="ident?i=SMC_SET_CTL">SMC_SET_CTL</a>(<a href="ident?i=lp">lp</a>, <a href="ident?i=ctl">ctl</a> &amp; ~CTL_LE_ENABLE);
<a name="L1203" href="source/drivers/net/ethernet/smsc/smc91x.c#L1203">1203</a>         <a href="ident?i=SMC_SET_CTL">SMC_SET_CTL</a>(<a href="ident?i=lp">lp</a>, <a href="ident?i=ctl">ctl</a>);
<a name="L1204" href="source/drivers/net/ethernet/smsc/smc91x.c#L1204">1204</a>         <a href="ident?i=SMC_SELECT_BANK">SMC_SELECT_BANK</a>(<a href="ident?i=lp">lp</a>, 2);
<a name="L1205" href="source/drivers/net/ethernet/smsc/smc91x.c#L1205">1205</a> }
<a name="L1206" href="source/drivers/net/ethernet/smsc/smc91x.c#L1206">1206</a> 
<a name="L1207" href="source/drivers/net/ethernet/smsc/smc91x.c#L1207">1207</a> <b><i>/*</i></b>
<a name="L1208" href="source/drivers/net/ethernet/smsc/smc91x.c#L1208">1208</a> <b><i> * This is the main routine of the driver, to handle the device when</i></b>
<a name="L1209" href="source/drivers/net/ethernet/smsc/smc91x.c#L1209">1209</a> <b><i> * it needs some attention.</i></b>
<a name="L1210" href="source/drivers/net/ethernet/smsc/smc91x.c#L1210">1210</a> <b><i> */</i></b>
<a name="L1211" href="source/drivers/net/ethernet/smsc/smc91x.c#L1211">1211</a> static <a href="ident?i=irqreturn_t">irqreturn_t</a> <a href="ident?i=smc_interrupt">smc_interrupt</a>(int <a href="ident?i=irq">irq</a>, void *<a href="ident?i=dev_id">dev_id</a>)
<a name="L1212" href="source/drivers/net/ethernet/smsc/smc91x.c#L1212">1212</a> {
<a name="L1213" href="source/drivers/net/ethernet/smsc/smc91x.c#L1213">1213</a>         struct <a href="ident?i=net_device">net_device</a> *<a href="ident?i=dev">dev</a> = <a href="ident?i=dev_id">dev_id</a>;
<a name="L1214" href="source/drivers/net/ethernet/smsc/smc91x.c#L1214">1214</a>         struct <a href="ident?i=smc_local">smc_local</a> *<a href="ident?i=lp">lp</a> = <a href="ident?i=netdev_priv">netdev_priv</a>(<a href="ident?i=dev">dev</a>);
<a name="L1215" href="source/drivers/net/ethernet/smsc/smc91x.c#L1215">1215</a>         void <a href="ident?i=__iomem">__iomem</a> *<a href="ident?i=ioaddr">ioaddr</a> = <a href="ident?i=lp">lp</a>-&gt;<a href="ident?i=base">base</a>;
<a name="L1216" href="source/drivers/net/ethernet/smsc/smc91x.c#L1216">1216</a>         int <a href="ident?i=status">status</a>, <a href="ident?i=mask">mask</a>, <a href="ident?i=timeout">timeout</a>, card_stats;
<a name="L1217" href="source/drivers/net/ethernet/smsc/smc91x.c#L1217">1217</a>         int saved_pointer;
<a name="L1218" href="source/drivers/net/ethernet/smsc/smc91x.c#L1218">1218</a> 
<a name="L1219" href="source/drivers/net/ethernet/smsc/smc91x.c#L1219">1219</a>         <a href="ident?i=DBG">DBG</a>(3, <a href="ident?i=dev">dev</a>, <i>"%s\n"</i>, <a href="ident?i=__func__">__func__</a>);
<a name="L1220" href="source/drivers/net/ethernet/smsc/smc91x.c#L1220">1220</a> 
<a name="L1221" href="source/drivers/net/ethernet/smsc/smc91x.c#L1221">1221</a>         <a href="ident?i=spin_lock">spin_lock</a>(&amp;<a href="ident?i=lp">lp</a>-&gt;<a href="ident?i=lock">lock</a>);
<a name="L1222" href="source/drivers/net/ethernet/smsc/smc91x.c#L1222">1222</a> 
<a name="L1223" href="source/drivers/net/ethernet/smsc/smc91x.c#L1223">1223</a>         <b><i>/* A preamble may be used when there is a potential race</i></b>
<a name="L1224" href="source/drivers/net/ethernet/smsc/smc91x.c#L1224">1224</a> <b><i>         * between the interruptible transmit functions and this</i></b>
<a name="L1225" href="source/drivers/net/ethernet/smsc/smc91x.c#L1225">1225</a> <b><i>         * ISR. */</i></b>
<a name="L1226" href="source/drivers/net/ethernet/smsc/smc91x.c#L1226">1226</a>         <a href="ident?i=SMC_INTERRUPT_PREAMBLE">SMC_INTERRUPT_PREAMBLE</a>;
<a name="L1227" href="source/drivers/net/ethernet/smsc/smc91x.c#L1227">1227</a> 
<a name="L1228" href="source/drivers/net/ethernet/smsc/smc91x.c#L1228">1228</a>         saved_pointer = <a href="ident?i=SMC_GET_PTR">SMC_GET_PTR</a>(<a href="ident?i=lp">lp</a>);
<a name="L1229" href="source/drivers/net/ethernet/smsc/smc91x.c#L1229">1229</a>         <a href="ident?i=mask">mask</a> = <a href="ident?i=SMC_GET_INT_MASK">SMC_GET_INT_MASK</a>(<a href="ident?i=lp">lp</a>);
<a name="L1230" href="source/drivers/net/ethernet/smsc/smc91x.c#L1230">1230</a>         <a href="ident?i=SMC_SET_INT_MASK">SMC_SET_INT_MASK</a>(<a href="ident?i=lp">lp</a>, 0);
<a name="L1231" href="source/drivers/net/ethernet/smsc/smc91x.c#L1231">1231</a> 
<a name="L1232" href="source/drivers/net/ethernet/smsc/smc91x.c#L1232">1232</a>         <b><i>/* set a timeout value, so I don't stay here forever */</i></b>
<a name="L1233" href="source/drivers/net/ethernet/smsc/smc91x.c#L1233">1233</a>         <a href="ident?i=timeout">timeout</a> = <a href="ident?i=MAX_IRQ_LOOPS">MAX_IRQ_LOOPS</a>;
<a name="L1234" href="source/drivers/net/ethernet/smsc/smc91x.c#L1234">1234</a> 
<a name="L1235" href="source/drivers/net/ethernet/smsc/smc91x.c#L1235">1235</a>         do {
<a name="L1236" href="source/drivers/net/ethernet/smsc/smc91x.c#L1236">1236</a>                 <a href="ident?i=status">status</a> = <a href="ident?i=SMC_GET_INT">SMC_GET_INT</a>(<a href="ident?i=lp">lp</a>);
<a name="L1237" href="source/drivers/net/ethernet/smsc/smc91x.c#L1237">1237</a> 
<a name="L1238" href="source/drivers/net/ethernet/smsc/smc91x.c#L1238">1238</a>                 <a href="ident?i=DBG">DBG</a>(2, <a href="ident?i=dev">dev</a>, <i>"INT 0x%02x MASK 0x%02x MEM 0x%04x FIFO 0x%04x\n"</i>,
<a name="L1239" href="source/drivers/net/ethernet/smsc/smc91x.c#L1239">1239</a>                     <a href="ident?i=status">status</a>, <a href="ident?i=mask">mask</a>,
<a name="L1240" href="source/drivers/net/ethernet/smsc/smc91x.c#L1240">1240</a>                     ({ int <a href="ident?i=meminfo">meminfo</a>; <a href="ident?i=SMC_SELECT_BANK">SMC_SELECT_BANK</a>(<a href="ident?i=lp">lp</a>, 0);
<a name="L1241" href="source/drivers/net/ethernet/smsc/smc91x.c#L1241">1241</a>                        <a href="ident?i=meminfo">meminfo</a> = <a href="ident?i=SMC_GET_MIR">SMC_GET_MIR</a>(<a href="ident?i=lp">lp</a>);
<a name="L1242" href="source/drivers/net/ethernet/smsc/smc91x.c#L1242">1242</a>                        <a href="ident?i=SMC_SELECT_BANK">SMC_SELECT_BANK</a>(<a href="ident?i=lp">lp</a>, 2); <a href="ident?i=meminfo">meminfo</a>; }),
<a name="L1243" href="source/drivers/net/ethernet/smsc/smc91x.c#L1243">1243</a>                     <a href="ident?i=SMC_GET_FIFO">SMC_GET_FIFO</a>(<a href="ident?i=lp">lp</a>));
<a name="L1244" href="source/drivers/net/ethernet/smsc/smc91x.c#L1244">1244</a> 
<a name="L1245" href="source/drivers/net/ethernet/smsc/smc91x.c#L1245">1245</a>                 <a href="ident?i=status">status</a> &amp;= <a href="ident?i=mask">mask</a>;
<a name="L1246" href="source/drivers/net/ethernet/smsc/smc91x.c#L1246">1246</a>                 if (!<a href="ident?i=status">status</a>)
<a name="L1247" href="source/drivers/net/ethernet/smsc/smc91x.c#L1247">1247</a>                         break;
<a name="L1248" href="source/drivers/net/ethernet/smsc/smc91x.c#L1248">1248</a> 
<a name="L1249" href="source/drivers/net/ethernet/smsc/smc91x.c#L1249">1249</a>                 if (<a href="ident?i=status">status</a> &amp; <a href="ident?i=IM_TX_INT">IM_TX_INT</a>) {
<a name="L1250" href="source/drivers/net/ethernet/smsc/smc91x.c#L1250">1250</a>                         <b><i>/* do this before RX as it will free memory quickly */</i></b>
<a name="L1251" href="source/drivers/net/ethernet/smsc/smc91x.c#L1251">1251</a>                         <a href="ident?i=DBG">DBG</a>(3, <a href="ident?i=dev">dev</a>, <i>"TX int\n"</i>);
<a name="L1252" href="source/drivers/net/ethernet/smsc/smc91x.c#L1252">1252</a>                         <a href="ident?i=smc_tx">smc_tx</a>(<a href="ident?i=dev">dev</a>);
<a name="L1253" href="source/drivers/net/ethernet/smsc/smc91x.c#L1253">1253</a>                         <a href="ident?i=SMC_ACK_INT">SMC_ACK_INT</a>(<a href="ident?i=lp">lp</a>, <a href="ident?i=IM_TX_INT">IM_TX_INT</a>);
<a name="L1254" href="source/drivers/net/ethernet/smsc/smc91x.c#L1254">1254</a>                         if (<a href="ident?i=THROTTLE_TX_PKTS">THROTTLE_TX_PKTS</a>)
<a name="L1255" href="source/drivers/net/ethernet/smsc/smc91x.c#L1255">1255</a>                                 <a href="ident?i=netif_wake_queue">netif_wake_queue</a>(<a href="ident?i=dev">dev</a>);
<a name="L1256" href="source/drivers/net/ethernet/smsc/smc91x.c#L1256">1256</a>                 } else if (<a href="ident?i=status">status</a> &amp; <a href="ident?i=IM_RCV_INT">IM_RCV_INT</a>) {
<a name="L1257" href="source/drivers/net/ethernet/smsc/smc91x.c#L1257">1257</a>                         <a href="ident?i=DBG">DBG</a>(3, <a href="ident?i=dev">dev</a>, <i>"RX irq\n"</i>);
<a name="L1258" href="source/drivers/net/ethernet/smsc/smc91x.c#L1258">1258</a>                         <a href="ident?i=smc_rcv">smc_rcv</a>(<a href="ident?i=dev">dev</a>);
<a name="L1259" href="source/drivers/net/ethernet/smsc/smc91x.c#L1259">1259</a>                 } else if (<a href="ident?i=status">status</a> &amp; <a href="ident?i=IM_ALLOC_INT">IM_ALLOC_INT</a>) {
<a name="L1260" href="source/drivers/net/ethernet/smsc/smc91x.c#L1260">1260</a>                         <a href="ident?i=DBG">DBG</a>(3, <a href="ident?i=dev">dev</a>, <i>"Allocation irq\n"</i>);
<a name="L1261" href="source/drivers/net/ethernet/smsc/smc91x.c#L1261">1261</a>                         <a href="ident?i=tasklet_hi_schedule">tasklet_hi_schedule</a>(&amp;<a href="ident?i=lp">lp</a>-&gt;tx_task);
<a name="L1262" href="source/drivers/net/ethernet/smsc/smc91x.c#L1262">1262</a>                         <a href="ident?i=mask">mask</a> &amp;= ~IM_ALLOC_INT;
<a name="L1263" href="source/drivers/net/ethernet/smsc/smc91x.c#L1263">1263</a>                 } else if (<a href="ident?i=status">status</a> &amp; <a href="ident?i=IM_TX_EMPTY_INT">IM_TX_EMPTY_INT</a>) {
<a name="L1264" href="source/drivers/net/ethernet/smsc/smc91x.c#L1264">1264</a>                         <a href="ident?i=DBG">DBG</a>(3, <a href="ident?i=dev">dev</a>, <i>"TX empty\n"</i>);
<a name="L1265" href="source/drivers/net/ethernet/smsc/smc91x.c#L1265">1265</a>                         <a href="ident?i=mask">mask</a> &amp;= ~IM_TX_EMPTY_INT;
<a name="L1266" href="source/drivers/net/ethernet/smsc/smc91x.c#L1266">1266</a> 
<a name="L1267" href="source/drivers/net/ethernet/smsc/smc91x.c#L1267">1267</a>                         <b><i>/* update stats */</i></b>
<a name="L1268" href="source/drivers/net/ethernet/smsc/smc91x.c#L1268">1268</a>                         <a href="ident?i=SMC_SELECT_BANK">SMC_SELECT_BANK</a>(<a href="ident?i=lp">lp</a>, 0);
<a name="L1269" href="source/drivers/net/ethernet/smsc/smc91x.c#L1269">1269</a>                         card_stats = <a href="ident?i=SMC_GET_COUNTER">SMC_GET_COUNTER</a>(<a href="ident?i=lp">lp</a>);
<a name="L1270" href="source/drivers/net/ethernet/smsc/smc91x.c#L1270">1270</a>                         <a href="ident?i=SMC_SELECT_BANK">SMC_SELECT_BANK</a>(<a href="ident?i=lp">lp</a>, 2);
<a name="L1271" href="source/drivers/net/ethernet/smsc/smc91x.c#L1271">1271</a> 
<a name="L1272" href="source/drivers/net/ethernet/smsc/smc91x.c#L1272">1272</a>                         <b><i>/* single collisions */</i></b>
<a name="L1273" href="source/drivers/net/ethernet/smsc/smc91x.c#L1273">1273</a>                         <a href="ident?i=dev">dev</a>-&gt;<a href="ident?i=stats">stats</a>.collisions += card_stats &amp; 0xF;
<a name="L1274" href="source/drivers/net/ethernet/smsc/smc91x.c#L1274">1274</a>                         card_stats &gt;&gt;= 4;
<a name="L1275" href="source/drivers/net/ethernet/smsc/smc91x.c#L1275">1275</a> 
<a name="L1276" href="source/drivers/net/ethernet/smsc/smc91x.c#L1276">1276</a>                         <b><i>/* multiple collisions */</i></b>
<a name="L1277" href="source/drivers/net/ethernet/smsc/smc91x.c#L1277">1277</a>                         <a href="ident?i=dev">dev</a>-&gt;<a href="ident?i=stats">stats</a>.collisions += card_stats &amp; 0xF;
<a name="L1278" href="source/drivers/net/ethernet/smsc/smc91x.c#L1278">1278</a>                 } else if (<a href="ident?i=status">status</a> &amp; <a href="ident?i=IM_RX_OVRN_INT">IM_RX_OVRN_INT</a>) {
<a name="L1279" href="source/drivers/net/ethernet/smsc/smc91x.c#L1279">1279</a>                         <a href="ident?i=DBG">DBG</a>(1, <a href="ident?i=dev">dev</a>, <i>"RX overrun (EPH_ST 0x%04x)\n"</i>,
<a name="L1280" href="source/drivers/net/ethernet/smsc/smc91x.c#L1280">1280</a>                             ({ int eph_st; <a href="ident?i=SMC_SELECT_BANK">SMC_SELECT_BANK</a>(<a href="ident?i=lp">lp</a>, 0);
<a name="L1281" href="source/drivers/net/ethernet/smsc/smc91x.c#L1281">1281</a>                                eph_st = <a href="ident?i=SMC_GET_EPH_STATUS">SMC_GET_EPH_STATUS</a>(<a href="ident?i=lp">lp</a>);
<a name="L1282" href="source/drivers/net/ethernet/smsc/smc91x.c#L1282">1282</a>                                <a href="ident?i=SMC_SELECT_BANK">SMC_SELECT_BANK</a>(<a href="ident?i=lp">lp</a>, 2); eph_st; }));
<a name="L1283" href="source/drivers/net/ethernet/smsc/smc91x.c#L1283">1283</a>                         <a href="ident?i=SMC_ACK_INT">SMC_ACK_INT</a>(<a href="ident?i=lp">lp</a>, <a href="ident?i=IM_RX_OVRN_INT">IM_RX_OVRN_INT</a>);
<a name="L1284" href="source/drivers/net/ethernet/smsc/smc91x.c#L1284">1284</a>                         <a href="ident?i=dev">dev</a>-&gt;<a href="ident?i=stats">stats</a>.rx_errors++;
<a name="L1285" href="source/drivers/net/ethernet/smsc/smc91x.c#L1285">1285</a>                         <a href="ident?i=dev">dev</a>-&gt;<a href="ident?i=stats">stats</a>.rx_fifo_errors++;
<a name="L1286" href="source/drivers/net/ethernet/smsc/smc91x.c#L1286">1286</a>                 } else if (<a href="ident?i=status">status</a> &amp; <a href="ident?i=IM_EPH_INT">IM_EPH_INT</a>) {
<a name="L1287" href="source/drivers/net/ethernet/smsc/smc91x.c#L1287">1287</a>                         <a href="ident?i=smc_eph_interrupt">smc_eph_interrupt</a>(<a href="ident?i=dev">dev</a>);
<a name="L1288" href="source/drivers/net/ethernet/smsc/smc91x.c#L1288">1288</a>                 } else if (<a href="ident?i=status">status</a> &amp; <a href="ident?i=IM_MDINT">IM_MDINT</a>) {
<a name="L1289" href="source/drivers/net/ethernet/smsc/smc91x.c#L1289">1289</a>                         <a href="ident?i=SMC_ACK_INT">SMC_ACK_INT</a>(<a href="ident?i=lp">lp</a>, <a href="ident?i=IM_MDINT">IM_MDINT</a>);
<a name="L1290" href="source/drivers/net/ethernet/smsc/smc91x.c#L1290">1290</a>                         <a href="ident?i=smc_phy_interrupt">smc_phy_interrupt</a>(<a href="ident?i=dev">dev</a>);
<a name="L1291" href="source/drivers/net/ethernet/smsc/smc91x.c#L1291">1291</a>                 } else if (<a href="ident?i=status">status</a> &amp; <a href="ident?i=IM_ERCV_INT">IM_ERCV_INT</a>) {
<a name="L1292" href="source/drivers/net/ethernet/smsc/smc91x.c#L1292">1292</a>                         <a href="ident?i=SMC_ACK_INT">SMC_ACK_INT</a>(<a href="ident?i=lp">lp</a>, <a href="ident?i=IM_ERCV_INT">IM_ERCV_INT</a>);
<a name="L1293" href="source/drivers/net/ethernet/smsc/smc91x.c#L1293">1293</a>                         <a href="ident?i=PRINTK">PRINTK</a>(<a href="ident?i=dev">dev</a>, <i>"UNSUPPORTED: ERCV INTERRUPT\n"</i>);
<a name="L1294" href="source/drivers/net/ethernet/smsc/smc91x.c#L1294">1294</a>                 }
<a name="L1295" href="source/drivers/net/ethernet/smsc/smc91x.c#L1295">1295</a>         } while (--<a href="ident?i=timeout">timeout</a>);
<a name="L1296" href="source/drivers/net/ethernet/smsc/smc91x.c#L1296">1296</a> 
<a name="L1297" href="source/drivers/net/ethernet/smsc/smc91x.c#L1297">1297</a>         <b><i>/* restore register states */</i></b>
<a name="L1298" href="source/drivers/net/ethernet/smsc/smc91x.c#L1298">1298</a>         <a href="ident?i=SMC_SET_PTR">SMC_SET_PTR</a>(<a href="ident?i=lp">lp</a>, saved_pointer);
<a name="L1299" href="source/drivers/net/ethernet/smsc/smc91x.c#L1299">1299</a>         <a href="ident?i=SMC_SET_INT_MASK">SMC_SET_INT_MASK</a>(<a href="ident?i=lp">lp</a>, <a href="ident?i=mask">mask</a>);
<a name="L1300" href="source/drivers/net/ethernet/smsc/smc91x.c#L1300">1300</a>         <a href="ident?i=spin_unlock">spin_unlock</a>(&amp;<a href="ident?i=lp">lp</a>-&gt;<a href="ident?i=lock">lock</a>);
<a name="L1301" href="source/drivers/net/ethernet/smsc/smc91x.c#L1301">1301</a> 
<a name="L1302" href="source/drivers/net/ethernet/smsc/smc91x.c#L1302">1302</a> #ifndef CONFIG_NET_POLL_CONTROLLER
<a name="L1303" href="source/drivers/net/ethernet/smsc/smc91x.c#L1303">1303</a>         if (<a href="ident?i=timeout">timeout</a> == <a href="ident?i=MAX_IRQ_LOOPS">MAX_IRQ_LOOPS</a>)
<a name="L1304" href="source/drivers/net/ethernet/smsc/smc91x.c#L1304">1304</a>                 <a href="ident?i=PRINTK">PRINTK</a>(<a href="ident?i=dev">dev</a>, <i>"spurious interrupt (mask = 0x%02x)\n"</i>,
<a name="L1305" href="source/drivers/net/ethernet/smsc/smc91x.c#L1305">1305</a>                        <a href="ident?i=mask">mask</a>);
<a name="L1306" href="source/drivers/net/ethernet/smsc/smc91x.c#L1306">1306</a> #endif
<a name="L1307" href="source/drivers/net/ethernet/smsc/smc91x.c#L1307">1307</a>         <a href="ident?i=DBG">DBG</a>(3, <a href="ident?i=dev">dev</a>, <i>"Interrupt done (%d loops)\n"</i>,
<a name="L1308" href="source/drivers/net/ethernet/smsc/smc91x.c#L1308">1308</a>             <a href="ident?i=MAX_IRQ_LOOPS">MAX_IRQ_LOOPS</a> - <a href="ident?i=timeout">timeout</a>);
<a name="L1309" href="source/drivers/net/ethernet/smsc/smc91x.c#L1309">1309</a> 
<a name="L1310" href="source/drivers/net/ethernet/smsc/smc91x.c#L1310">1310</a>         <b><i>/*</i></b>
<a name="L1311" href="source/drivers/net/ethernet/smsc/smc91x.c#L1311">1311</a> <b><i>         * We return IRQ_HANDLED unconditionally here even if there was</i></b>
<a name="L1312" href="source/drivers/net/ethernet/smsc/smc91x.c#L1312">1312</a> <b><i>         * nothing to do.  There is a possibility that a packet might</i></b>
<a name="L1313" href="source/drivers/net/ethernet/smsc/smc91x.c#L1313">1313</a> <b><i>         * get enqueued into the chip right after TX_EMPTY_INT is raised</i></b>
<a name="L1314" href="source/drivers/net/ethernet/smsc/smc91x.c#L1314">1314</a> <b><i>         * but just before the CPU acknowledges the IRQ.</i></b>
<a name="L1315" href="source/drivers/net/ethernet/smsc/smc91x.c#L1315">1315</a> <b><i>         * Better take an unneeded IRQ in some occasions than complexifying</i></b>
<a name="L1316" href="source/drivers/net/ethernet/smsc/smc91x.c#L1316">1316</a> <b><i>         * the code for all cases.</i></b>
<a name="L1317" href="source/drivers/net/ethernet/smsc/smc91x.c#L1317">1317</a> <b><i>         */</i></b>
<a name="L1318" href="source/drivers/net/ethernet/smsc/smc91x.c#L1318">1318</a>         return <a href="ident?i=IRQ_HANDLED">IRQ_HANDLED</a>;
<a name="L1319" href="source/drivers/net/ethernet/smsc/smc91x.c#L1319">1319</a> }
<a name="L1320" href="source/drivers/net/ethernet/smsc/smc91x.c#L1320">1320</a> 
<a name="L1321" href="source/drivers/net/ethernet/smsc/smc91x.c#L1321">1321</a> #ifdef CONFIG_NET_POLL_CONTROLLER
<a name="L1322" href="source/drivers/net/ethernet/smsc/smc91x.c#L1322">1322</a> <b><i>/*</i></b>
<a name="L1323" href="source/drivers/net/ethernet/smsc/smc91x.c#L1323">1323</a> <b><i> * Polling receive - used by netconsole and other diagnostic tools</i></b>
<a name="L1324" href="source/drivers/net/ethernet/smsc/smc91x.c#L1324">1324</a> <b><i> * to allow network i/o with interrupts disabled.</i></b>
<a name="L1325" href="source/drivers/net/ethernet/smsc/smc91x.c#L1325">1325</a> <b><i> */</i></b>
<a name="L1326" href="source/drivers/net/ethernet/smsc/smc91x.c#L1326">1326</a> static void <a href="ident?i=smc_poll_controller">smc_poll_controller</a>(struct <a href="ident?i=net_device">net_device</a> *<a href="ident?i=dev">dev</a>)
<a name="L1327" href="source/drivers/net/ethernet/smsc/smc91x.c#L1327">1327</a> {
<a name="L1328" href="source/drivers/net/ethernet/smsc/smc91x.c#L1328">1328</a>         <a href="ident?i=disable_irq">disable_irq</a>(<a href="ident?i=dev">dev</a>-&gt;<a href="ident?i=irq">irq</a>);
<a name="L1329" href="source/drivers/net/ethernet/smsc/smc91x.c#L1329">1329</a>         <a href="ident?i=smc_interrupt">smc_interrupt</a>(<a href="ident?i=dev">dev</a>-&gt;<a href="ident?i=irq">irq</a>, <a href="ident?i=dev">dev</a>);
<a name="L1330" href="source/drivers/net/ethernet/smsc/smc91x.c#L1330">1330</a>         <a href="ident?i=enable_irq">enable_irq</a>(<a href="ident?i=dev">dev</a>-&gt;<a href="ident?i=irq">irq</a>);
<a name="L1331" href="source/drivers/net/ethernet/smsc/smc91x.c#L1331">1331</a> }
<a name="L1332" href="source/drivers/net/ethernet/smsc/smc91x.c#L1332">1332</a> #endif
<a name="L1333" href="source/drivers/net/ethernet/smsc/smc91x.c#L1333">1333</a> 
<a name="L1334" href="source/drivers/net/ethernet/smsc/smc91x.c#L1334">1334</a> <b><i>/* Our watchdog timed out. Called by the networking layer */</i></b>
<a name="L1335" href="source/drivers/net/ethernet/smsc/smc91x.c#L1335">1335</a> static void <a href="ident?i=smc_timeout">smc_timeout</a>(struct <a href="ident?i=net_device">net_device</a> *<a href="ident?i=dev">dev</a>)
<a name="L1336" href="source/drivers/net/ethernet/smsc/smc91x.c#L1336">1336</a> {
<a name="L1337" href="source/drivers/net/ethernet/smsc/smc91x.c#L1337">1337</a>         struct <a href="ident?i=smc_local">smc_local</a> *<a href="ident?i=lp">lp</a> = <a href="ident?i=netdev_priv">netdev_priv</a>(<a href="ident?i=dev">dev</a>);
<a name="L1338" href="source/drivers/net/ethernet/smsc/smc91x.c#L1338">1338</a>         void <a href="ident?i=__iomem">__iomem</a> *<a href="ident?i=ioaddr">ioaddr</a> = <a href="ident?i=lp">lp</a>-&gt;<a href="ident?i=base">base</a>;
<a name="L1339" href="source/drivers/net/ethernet/smsc/smc91x.c#L1339">1339</a>         int <a href="ident?i=status">status</a>, <a href="ident?i=mask">mask</a>, eph_st, <a href="ident?i=meminfo">meminfo</a>, <a href="ident?i=fifo">fifo</a>;
<a name="L1340" href="source/drivers/net/ethernet/smsc/smc91x.c#L1340">1340</a> 
<a name="L1341" href="source/drivers/net/ethernet/smsc/smc91x.c#L1341">1341</a>         <a href="ident?i=DBG">DBG</a>(2, <a href="ident?i=dev">dev</a>, <i>"%s\n"</i>, <a href="ident?i=__func__">__func__</a>);
<a name="L1342" href="source/drivers/net/ethernet/smsc/smc91x.c#L1342">1342</a> 
<a name="L1343" href="source/drivers/net/ethernet/smsc/smc91x.c#L1343">1343</a>         <a href="ident?i=spin_lock_irq">spin_lock_irq</a>(&amp;<a href="ident?i=lp">lp</a>-&gt;<a href="ident?i=lock">lock</a>);
<a name="L1344" href="source/drivers/net/ethernet/smsc/smc91x.c#L1344">1344</a>         <a href="ident?i=status">status</a> = <a href="ident?i=SMC_GET_INT">SMC_GET_INT</a>(<a href="ident?i=lp">lp</a>);
<a name="L1345" href="source/drivers/net/ethernet/smsc/smc91x.c#L1345">1345</a>         <a href="ident?i=mask">mask</a> = <a href="ident?i=SMC_GET_INT_MASK">SMC_GET_INT_MASK</a>(<a href="ident?i=lp">lp</a>);
<a name="L1346" href="source/drivers/net/ethernet/smsc/smc91x.c#L1346">1346</a>         <a href="ident?i=fifo">fifo</a> = <a href="ident?i=SMC_GET_FIFO">SMC_GET_FIFO</a>(<a href="ident?i=lp">lp</a>);
<a name="L1347" href="source/drivers/net/ethernet/smsc/smc91x.c#L1347">1347</a>         <a href="ident?i=SMC_SELECT_BANK">SMC_SELECT_BANK</a>(<a href="ident?i=lp">lp</a>, 0);
<a name="L1348" href="source/drivers/net/ethernet/smsc/smc91x.c#L1348">1348</a>         eph_st = <a href="ident?i=SMC_GET_EPH_STATUS">SMC_GET_EPH_STATUS</a>(<a href="ident?i=lp">lp</a>);
<a name="L1349" href="source/drivers/net/ethernet/smsc/smc91x.c#L1349">1349</a>         <a href="ident?i=meminfo">meminfo</a> = <a href="ident?i=SMC_GET_MIR">SMC_GET_MIR</a>(<a href="ident?i=lp">lp</a>);
<a name="L1350" href="source/drivers/net/ethernet/smsc/smc91x.c#L1350">1350</a>         <a href="ident?i=SMC_SELECT_BANK">SMC_SELECT_BANK</a>(<a href="ident?i=lp">lp</a>, 2);
<a name="L1351" href="source/drivers/net/ethernet/smsc/smc91x.c#L1351">1351</a>         <a href="ident?i=spin_unlock_irq">spin_unlock_irq</a>(&amp;<a href="ident?i=lp">lp</a>-&gt;<a href="ident?i=lock">lock</a>);
<a name="L1352" href="source/drivers/net/ethernet/smsc/smc91x.c#L1352">1352</a>         <a href="ident?i=PRINTK">PRINTK</a>(<a href="ident?i=dev">dev</a>, <i>"TX timeout (INT 0x%02x INTMASK 0x%02x MEM 0x%04x FIFO 0x%04x EPH_ST 0x%04x)\n"</i>,
<a name="L1353" href="source/drivers/net/ethernet/smsc/smc91x.c#L1353">1353</a>                <a href="ident?i=status">status</a>, <a href="ident?i=mask">mask</a>, <a href="ident?i=meminfo">meminfo</a>, <a href="ident?i=fifo">fifo</a>, eph_st);
<a name="L1354" href="source/drivers/net/ethernet/smsc/smc91x.c#L1354">1354</a> 
<a name="L1355" href="source/drivers/net/ethernet/smsc/smc91x.c#L1355">1355</a>         <a href="ident?i=smc_reset">smc_reset</a>(<a href="ident?i=dev">dev</a>);
<a name="L1356" href="source/drivers/net/ethernet/smsc/smc91x.c#L1356">1356</a>         <a href="ident?i=smc_enable">smc_enable</a>(<a href="ident?i=dev">dev</a>);
<a name="L1357" href="source/drivers/net/ethernet/smsc/smc91x.c#L1357">1357</a> 
<a name="L1358" href="source/drivers/net/ethernet/smsc/smc91x.c#L1358">1358</a>         <b><i>/*</i></b>
<a name="L1359" href="source/drivers/net/ethernet/smsc/smc91x.c#L1359">1359</a> <b><i>         * Reconfiguring the PHY doesn't seem like a bad idea here, but</i></b>
<a name="L1360" href="source/drivers/net/ethernet/smsc/smc91x.c#L1360">1360</a> <b><i>         * smc_phy_configure() calls msleep() which calls schedule_timeout()</i></b>
<a name="L1361" href="source/drivers/net/ethernet/smsc/smc91x.c#L1361">1361</a> <b><i>         * which calls schedule().  Hence we use a work queue.</i></b>
<a name="L1362" href="source/drivers/net/ethernet/smsc/smc91x.c#L1362">1362</a> <b><i>         */</i></b>
<a name="L1363" href="source/drivers/net/ethernet/smsc/smc91x.c#L1363">1363</a>         if (<a href="ident?i=lp">lp</a>-&gt;phy_type != 0)
<a name="L1364" href="source/drivers/net/ethernet/smsc/smc91x.c#L1364">1364</a>                 <a href="ident?i=schedule_work">schedule_work</a>(&amp;<a href="ident?i=lp">lp</a>-&gt;phy_configure);
<a name="L1365" href="source/drivers/net/ethernet/smsc/smc91x.c#L1365">1365</a> 
<a name="L1366" href="source/drivers/net/ethernet/smsc/smc91x.c#L1366">1366</a>         <b><i>/* We can accept TX packets again */</i></b>
<a name="L1367" href="source/drivers/net/ethernet/smsc/smc91x.c#L1367">1367</a>         <a href="ident?i=netif_trans_update">netif_trans_update</a>(<a href="ident?i=dev">dev</a>); <b><i>/* prevent tx timeout */</i></b>
<a name="L1368" href="source/drivers/net/ethernet/smsc/smc91x.c#L1368">1368</a>         <a href="ident?i=netif_wake_queue">netif_wake_queue</a>(<a href="ident?i=dev">dev</a>);
<a name="L1369" href="source/drivers/net/ethernet/smsc/smc91x.c#L1369">1369</a> }
<a name="L1370" href="source/drivers/net/ethernet/smsc/smc91x.c#L1370">1370</a> 
<a name="L1371" href="source/drivers/net/ethernet/smsc/smc91x.c#L1371">1371</a> <b><i>/*</i></b>
<a name="L1372" href="source/drivers/net/ethernet/smsc/smc91x.c#L1372">1372</a> <b><i> * This routine will, depending on the values passed to it,</i></b>
<a name="L1373" href="source/drivers/net/ethernet/smsc/smc91x.c#L1373">1373</a> <b><i> * either make it accept multicast packets, go into</i></b>
<a name="L1374" href="source/drivers/net/ethernet/smsc/smc91x.c#L1374">1374</a> <b><i> * promiscuous mode (for TCPDUMP and cousins) or accept</i></b>
<a name="L1375" href="source/drivers/net/ethernet/smsc/smc91x.c#L1375">1375</a> <b><i> * a select set of multicast packets</i></b>
<a name="L1376" href="source/drivers/net/ethernet/smsc/smc91x.c#L1376">1376</a> <b><i> */</i></b>
<a name="L1377" href="source/drivers/net/ethernet/smsc/smc91x.c#L1377">1377</a> static void <a href="ident?i=smc_set_multicast_list">smc_set_multicast_list</a>(struct <a href="ident?i=net_device">net_device</a> *<a href="ident?i=dev">dev</a>)
<a name="L1378" href="source/drivers/net/ethernet/smsc/smc91x.c#L1378">1378</a> {
<a name="L1379" href="source/drivers/net/ethernet/smsc/smc91x.c#L1379">1379</a>         struct <a href="ident?i=smc_local">smc_local</a> *<a href="ident?i=lp">lp</a> = <a href="ident?i=netdev_priv">netdev_priv</a>(<a href="ident?i=dev">dev</a>);
<a name="L1380" href="source/drivers/net/ethernet/smsc/smc91x.c#L1380">1380</a>         void <a href="ident?i=__iomem">__iomem</a> *<a href="ident?i=ioaddr">ioaddr</a> = <a href="ident?i=lp">lp</a>-&gt;<a href="ident?i=base">base</a>;
<a name="L1381" href="source/drivers/net/ethernet/smsc/smc91x.c#L1381">1381</a>         unsigned char multicast_table[8];
<a name="L1382" href="source/drivers/net/ethernet/smsc/smc91x.c#L1382">1382</a>         int update_multicast = 0;
<a name="L1383" href="source/drivers/net/ethernet/smsc/smc91x.c#L1383">1383</a> 
<a name="L1384" href="source/drivers/net/ethernet/smsc/smc91x.c#L1384">1384</a>         <a href="ident?i=DBG">DBG</a>(2, <a href="ident?i=dev">dev</a>, <i>"%s\n"</i>, <a href="ident?i=__func__">__func__</a>);
<a name="L1385" href="source/drivers/net/ethernet/smsc/smc91x.c#L1385">1385</a> 
<a name="L1386" href="source/drivers/net/ethernet/smsc/smc91x.c#L1386">1386</a>         if (<a href="ident?i=dev">dev</a>-&gt;<a href="ident?i=flags">flags</a> &amp; <a href="ident?i=IFF_PROMISC">IFF_PROMISC</a>) {
<a name="L1387" href="source/drivers/net/ethernet/smsc/smc91x.c#L1387">1387</a>                 <a href="ident?i=DBG">DBG</a>(2, <a href="ident?i=dev">dev</a>, <i>"RCR_PRMS\n"</i>);
<a name="L1388" href="source/drivers/net/ethernet/smsc/smc91x.c#L1388">1388</a>                 <a href="ident?i=lp">lp</a>-&gt;rcr_cur_mode |= <a href="ident?i=RCR_PRMS">RCR_PRMS</a>;
<a name="L1389" href="source/drivers/net/ethernet/smsc/smc91x.c#L1389">1389</a>         }
<a name="L1390" href="source/drivers/net/ethernet/smsc/smc91x.c#L1390">1390</a> 
<a name="L1391" href="source/drivers/net/ethernet/smsc/smc91x.c#L1391">1391</a> <b><i>/* BUG?  I never disable promiscuous mode if multicasting was turned on.</i></b>
<a name="L1392" href="source/drivers/net/ethernet/smsc/smc91x.c#L1392">1392</a> <b><i>   Now, I turn off promiscuous mode, but I don't do anything to multicasting</i></b>
<a name="L1393" href="source/drivers/net/ethernet/smsc/smc91x.c#L1393">1393</a> <b><i>   when promiscuous mode is turned on.</i></b>
<a name="L1394" href="source/drivers/net/ethernet/smsc/smc91x.c#L1394">1394</a> <b><i>*/</i></b>
<a name="L1395" href="source/drivers/net/ethernet/smsc/smc91x.c#L1395">1395</a> 
<a name="L1396" href="source/drivers/net/ethernet/smsc/smc91x.c#L1396">1396</a>         <b><i>/*</i></b>
<a name="L1397" href="source/drivers/net/ethernet/smsc/smc91x.c#L1397">1397</a> <b><i>         * Here, I am setting this to accept all multicast packets.</i></b>
<a name="L1398" href="source/drivers/net/ethernet/smsc/smc91x.c#L1398">1398</a> <b><i>         * I don't need to zero the multicast table, because the flag is</i></b>
<a name="L1399" href="source/drivers/net/ethernet/smsc/smc91x.c#L1399">1399</a> <b><i>         * checked before the table is</i></b>
<a name="L1400" href="source/drivers/net/ethernet/smsc/smc91x.c#L1400">1400</a> <b><i>         */</i></b>
<a name="L1401" href="source/drivers/net/ethernet/smsc/smc91x.c#L1401">1401</a>         else if (<a href="ident?i=dev">dev</a>-&gt;<a href="ident?i=flags">flags</a> &amp; <a href="ident?i=IFF_ALLMULTI">IFF_ALLMULTI</a> || <a href="ident?i=netdev_mc_count">netdev_mc_count</a>(<a href="ident?i=dev">dev</a>) &gt; 16) {
<a name="L1402" href="source/drivers/net/ethernet/smsc/smc91x.c#L1402">1402</a>                 <a href="ident?i=DBG">DBG</a>(2, <a href="ident?i=dev">dev</a>, <i>"RCR_ALMUL\n"</i>);
<a name="L1403" href="source/drivers/net/ethernet/smsc/smc91x.c#L1403">1403</a>                 <a href="ident?i=lp">lp</a>-&gt;rcr_cur_mode |= <a href="ident?i=RCR_ALMUL">RCR_ALMUL</a>;
<a name="L1404" href="source/drivers/net/ethernet/smsc/smc91x.c#L1404">1404</a>         }
<a name="L1405" href="source/drivers/net/ethernet/smsc/smc91x.c#L1405">1405</a> 
<a name="L1406" href="source/drivers/net/ethernet/smsc/smc91x.c#L1406">1406</a>         <b><i>/*</i></b>
<a name="L1407" href="source/drivers/net/ethernet/smsc/smc91x.c#L1407">1407</a> <b><i>         * This sets the internal hardware table to filter out unwanted</i></b>
<a name="L1408" href="source/drivers/net/ethernet/smsc/smc91x.c#L1408">1408</a> <b><i>         * multicast packets before they take up memory.</i></b>
<a name="L1409" href="source/drivers/net/ethernet/smsc/smc91x.c#L1409">1409</a> <b><i>         *</i></b>
<a name="L1410" href="source/drivers/net/ethernet/smsc/smc91x.c#L1410">1410</a> <b><i>         * The SMC chip uses a hash table where the high 6 bits of the CRC of</i></b>
<a name="L1411" href="source/drivers/net/ethernet/smsc/smc91x.c#L1411">1411</a> <b><i>         * address are the offset into the table.  If that bit is 1, then the</i></b>
<a name="L1412" href="source/drivers/net/ethernet/smsc/smc91x.c#L1412">1412</a> <b><i>         * multicast packet is accepted.  Otherwise, it's dropped silently.</i></b>
<a name="L1413" href="source/drivers/net/ethernet/smsc/smc91x.c#L1413">1413</a> <b><i>         *</i></b>
<a name="L1414" href="source/drivers/net/ethernet/smsc/smc91x.c#L1414">1414</a> <b><i>         * To use the 6 bits as an offset into the table, the high 3 bits are</i></b>
<a name="L1415" href="source/drivers/net/ethernet/smsc/smc91x.c#L1415">1415</a> <b><i>         * the number of the 8 bit register, while the low 3 bits are the bit</i></b>
<a name="L1416" href="source/drivers/net/ethernet/smsc/smc91x.c#L1416">1416</a> <b><i>         * within that register.</i></b>
<a name="L1417" href="source/drivers/net/ethernet/smsc/smc91x.c#L1417">1417</a> <b><i>         */</i></b>
<a name="L1418" href="source/drivers/net/ethernet/smsc/smc91x.c#L1418">1418</a>         else if (!<a href="ident?i=netdev_mc_empty">netdev_mc_empty</a>(<a href="ident?i=dev">dev</a>)) {
<a name="L1419" href="source/drivers/net/ethernet/smsc/smc91x.c#L1419">1419</a>                 struct <a href="ident?i=netdev_hw_addr">netdev_hw_addr</a> *ha;
<a name="L1420" href="source/drivers/net/ethernet/smsc/smc91x.c#L1420">1420</a> 
<a name="L1421" href="source/drivers/net/ethernet/smsc/smc91x.c#L1421">1421</a>                 <b><i>/* table for flipping the order of 3 bits */</i></b>
<a name="L1422" href="source/drivers/net/ethernet/smsc/smc91x.c#L1422">1422</a>                 static const unsigned char invert3[] = {0, 4, 2, 6, 1, 5, 3, 7};
<a name="L1423" href="source/drivers/net/ethernet/smsc/smc91x.c#L1423">1423</a> 
<a name="L1424" href="source/drivers/net/ethernet/smsc/smc91x.c#L1424">1424</a>                 <b><i>/* start with a table of all zeros: reject all */</i></b>
<a name="L1425" href="source/drivers/net/ethernet/smsc/smc91x.c#L1425">1425</a>                 <a href="ident?i=memset">memset</a>(multicast_table, 0, sizeof(multicast_table));
<a name="L1426" href="source/drivers/net/ethernet/smsc/smc91x.c#L1426">1426</a> 
<a name="L1427" href="source/drivers/net/ethernet/smsc/smc91x.c#L1427">1427</a>                 <a href="ident?i=netdev_for_each_mc_addr">netdev_for_each_mc_addr</a>(ha, <a href="ident?i=dev">dev</a>) {
<a name="L1428" href="source/drivers/net/ethernet/smsc/smc91x.c#L1428">1428</a>                         int position;
<a name="L1429" href="source/drivers/net/ethernet/smsc/smc91x.c#L1429">1429</a> 
<a name="L1430" href="source/drivers/net/ethernet/smsc/smc91x.c#L1430">1430</a>                         <b><i>/* only use the low order bits */</i></b>
<a name="L1431" href="source/drivers/net/ethernet/smsc/smc91x.c#L1431">1431</a>                         position = <a href="ident?i=crc32_le">crc32_le</a>(~0, ha-&gt;<a href="ident?i=addr">addr</a>, 6) &amp; 0x3f;
<a name="L1432" href="source/drivers/net/ethernet/smsc/smc91x.c#L1432">1432</a> 
<a name="L1433" href="source/drivers/net/ethernet/smsc/smc91x.c#L1433">1433</a>                         <b><i>/* do some messy swapping to put the bit in the right spot */</i></b>
<a name="L1434" href="source/drivers/net/ethernet/smsc/smc91x.c#L1434">1434</a>                         multicast_table[invert3[position&amp;7]] |=
<a name="L1435" href="source/drivers/net/ethernet/smsc/smc91x.c#L1435">1435</a>                                 (1&lt;&lt;invert3[(position&gt;&gt;3)&amp;7]);
<a name="L1436" href="source/drivers/net/ethernet/smsc/smc91x.c#L1436">1436</a>                 }
<a name="L1437" href="source/drivers/net/ethernet/smsc/smc91x.c#L1437">1437</a> 
<a name="L1438" href="source/drivers/net/ethernet/smsc/smc91x.c#L1438">1438</a>                 <b><i>/* be sure I get rid of flags I might have set */</i></b>
<a name="L1439" href="source/drivers/net/ethernet/smsc/smc91x.c#L1439">1439</a>                 <a href="ident?i=lp">lp</a>-&gt;rcr_cur_mode &amp;= ~(<a href="ident?i=RCR_PRMS">RCR_PRMS</a> | <a href="ident?i=RCR_ALMUL">RCR_ALMUL</a>);
<a name="L1440" href="source/drivers/net/ethernet/smsc/smc91x.c#L1440">1440</a> 
<a name="L1441" href="source/drivers/net/ethernet/smsc/smc91x.c#L1441">1441</a>                 <b><i>/* now, the table can be loaded into the chipset */</i></b>
<a name="L1442" href="source/drivers/net/ethernet/smsc/smc91x.c#L1442">1442</a>                 update_multicast = 1;
<a name="L1443" href="source/drivers/net/ethernet/smsc/smc91x.c#L1443">1443</a>         } else  {
<a name="L1444" href="source/drivers/net/ethernet/smsc/smc91x.c#L1444">1444</a>                 <a href="ident?i=DBG">DBG</a>(2, <a href="ident?i=dev">dev</a>, <i>"~(RCR_PRMS|RCR_ALMUL)\n"</i>);
<a name="L1445" href="source/drivers/net/ethernet/smsc/smc91x.c#L1445">1445</a>                 <a href="ident?i=lp">lp</a>-&gt;rcr_cur_mode &amp;= ~(<a href="ident?i=RCR_PRMS">RCR_PRMS</a> | <a href="ident?i=RCR_ALMUL">RCR_ALMUL</a>);
<a name="L1446" href="source/drivers/net/ethernet/smsc/smc91x.c#L1446">1446</a> 
<a name="L1447" href="source/drivers/net/ethernet/smsc/smc91x.c#L1447">1447</a>                 <b><i>/*</i></b>
<a name="L1448" href="source/drivers/net/ethernet/smsc/smc91x.c#L1448">1448</a> <b><i>                 * since I'm disabling all multicast entirely, I need to</i></b>
<a name="L1449" href="source/drivers/net/ethernet/smsc/smc91x.c#L1449">1449</a> <b><i>                 * clear the multicast list</i></b>
<a name="L1450" href="source/drivers/net/ethernet/smsc/smc91x.c#L1450">1450</a> <b><i>                 */</i></b>
<a name="L1451" href="source/drivers/net/ethernet/smsc/smc91x.c#L1451">1451</a>                 <a href="ident?i=memset">memset</a>(multicast_table, 0, sizeof(multicast_table));
<a name="L1452" href="source/drivers/net/ethernet/smsc/smc91x.c#L1452">1452</a>                 update_multicast = 1;
<a name="L1453" href="source/drivers/net/ethernet/smsc/smc91x.c#L1453">1453</a>         }
<a name="L1454" href="source/drivers/net/ethernet/smsc/smc91x.c#L1454">1454</a> 
<a name="L1455" href="source/drivers/net/ethernet/smsc/smc91x.c#L1455">1455</a>         <a href="ident?i=spin_lock_irq">spin_lock_irq</a>(&amp;<a href="ident?i=lp">lp</a>-&gt;<a href="ident?i=lock">lock</a>);
<a name="L1456" href="source/drivers/net/ethernet/smsc/smc91x.c#L1456">1456</a>         <a href="ident?i=SMC_SELECT_BANK">SMC_SELECT_BANK</a>(<a href="ident?i=lp">lp</a>, 0);
<a name="L1457" href="source/drivers/net/ethernet/smsc/smc91x.c#L1457">1457</a>         <a href="ident?i=SMC_SET_RCR">SMC_SET_RCR</a>(<a href="ident?i=lp">lp</a>, <a href="ident?i=lp">lp</a>-&gt;rcr_cur_mode);
<a name="L1458" href="source/drivers/net/ethernet/smsc/smc91x.c#L1458">1458</a>         if (update_multicast) {
<a name="L1459" href="source/drivers/net/ethernet/smsc/smc91x.c#L1459">1459</a>                 <a href="ident?i=SMC_SELECT_BANK">SMC_SELECT_BANK</a>(<a href="ident?i=lp">lp</a>, 3);
<a name="L1460" href="source/drivers/net/ethernet/smsc/smc91x.c#L1460">1460</a>                 <a href="ident?i=SMC_SET_MCAST">SMC_SET_MCAST</a>(<a href="ident?i=lp">lp</a>, multicast_table);
<a name="L1461" href="source/drivers/net/ethernet/smsc/smc91x.c#L1461">1461</a>         }
<a name="L1462" href="source/drivers/net/ethernet/smsc/smc91x.c#L1462">1462</a>         <a href="ident?i=SMC_SELECT_BANK">SMC_SELECT_BANK</a>(<a href="ident?i=lp">lp</a>, 2);
<a name="L1463" href="source/drivers/net/ethernet/smsc/smc91x.c#L1463">1463</a>         <a href="ident?i=spin_unlock_irq">spin_unlock_irq</a>(&amp;<a href="ident?i=lp">lp</a>-&gt;<a href="ident?i=lock">lock</a>);
<a name="L1464" href="source/drivers/net/ethernet/smsc/smc91x.c#L1464">1464</a> }
<a name="L1465" href="source/drivers/net/ethernet/smsc/smc91x.c#L1465">1465</a> 
<a name="L1466" href="source/drivers/net/ethernet/smsc/smc91x.c#L1466">1466</a> 
<a name="L1467" href="source/drivers/net/ethernet/smsc/smc91x.c#L1467">1467</a> <b><i>/*</i></b>
<a name="L1468" href="source/drivers/net/ethernet/smsc/smc91x.c#L1468">1468</a> <b><i> * Open and Initialize the board</i></b>
<a name="L1469" href="source/drivers/net/ethernet/smsc/smc91x.c#L1469">1469</a> <b><i> *</i></b>
<a name="L1470" href="source/drivers/net/ethernet/smsc/smc91x.c#L1470">1470</a> <b><i> * Set up everything, reset the card, etc..</i></b>
<a name="L1471" href="source/drivers/net/ethernet/smsc/smc91x.c#L1471">1471</a> <b><i> */</i></b>
<a name="L1472" href="source/drivers/net/ethernet/smsc/smc91x.c#L1472">1472</a> static int
<a name="L1473" href="source/drivers/net/ethernet/smsc/smc91x.c#L1473">1473</a> <a href="ident?i=smc_open">smc_open</a>(struct <a href="ident?i=net_device">net_device</a> *<a href="ident?i=dev">dev</a>)
<a name="L1474" href="source/drivers/net/ethernet/smsc/smc91x.c#L1474">1474</a> {
<a name="L1475" href="source/drivers/net/ethernet/smsc/smc91x.c#L1475">1475</a>         struct <a href="ident?i=smc_local">smc_local</a> *<a href="ident?i=lp">lp</a> = <a href="ident?i=netdev_priv">netdev_priv</a>(<a href="ident?i=dev">dev</a>);
<a name="L1476" href="source/drivers/net/ethernet/smsc/smc91x.c#L1476">1476</a> 
<a name="L1477" href="source/drivers/net/ethernet/smsc/smc91x.c#L1477">1477</a>         <a href="ident?i=DBG">DBG</a>(2, <a href="ident?i=dev">dev</a>, <i>"%s\n"</i>, <a href="ident?i=__func__">__func__</a>);
<a name="L1478" href="source/drivers/net/ethernet/smsc/smc91x.c#L1478">1478</a> 
<a name="L1479" href="source/drivers/net/ethernet/smsc/smc91x.c#L1479">1479</a>         <b><i>/* Setup the default Register Modes */</i></b>
<a name="L1480" href="source/drivers/net/ethernet/smsc/smc91x.c#L1480">1480</a>         <a href="ident?i=lp">lp</a>-&gt;tcr_cur_mode = <a href="ident?i=TCR_DEFAULT">TCR_DEFAULT</a>;
<a name="L1481" href="source/drivers/net/ethernet/smsc/smc91x.c#L1481">1481</a>         <a href="ident?i=lp">lp</a>-&gt;rcr_cur_mode = <a href="ident?i=RCR_DEFAULT">RCR_DEFAULT</a>;
<a name="L1482" href="source/drivers/net/ethernet/smsc/smc91x.c#L1482">1482</a>         <a href="ident?i=lp">lp</a>-&gt;rpc_cur_mode = <a href="ident?i=RPC_DEFAULT">RPC_DEFAULT</a> |
<a name="L1483" href="source/drivers/net/ethernet/smsc/smc91x.c#L1483">1483</a>                                 <a href="ident?i=lp">lp</a>-&gt;<a href="ident?i=cfg">cfg</a>.leda &lt;&lt; <a href="ident?i=RPC_LSXA_SHFT">RPC_LSXA_SHFT</a> |
<a name="L1484" href="source/drivers/net/ethernet/smsc/smc91x.c#L1484">1484</a>                                 <a href="ident?i=lp">lp</a>-&gt;<a href="ident?i=cfg">cfg</a>.ledb &lt;&lt; <a href="ident?i=RPC_LSXB_SHFT">RPC_LSXB_SHFT</a>;
<a name="L1485" href="source/drivers/net/ethernet/smsc/smc91x.c#L1485">1485</a> 
<a name="L1486" href="source/drivers/net/ethernet/smsc/smc91x.c#L1486">1486</a>         <b><i>/*</i></b>
<a name="L1487" href="source/drivers/net/ethernet/smsc/smc91x.c#L1487">1487</a> <b><i>         * If we are not using a MII interface, we need to</i></b>
<a name="L1488" href="source/drivers/net/ethernet/smsc/smc91x.c#L1488">1488</a> <b><i>         * monitor our own carrier signal to detect faults.</i></b>
<a name="L1489" href="source/drivers/net/ethernet/smsc/smc91x.c#L1489">1489</a> <b><i>         */</i></b>
<a name="L1490" href="source/drivers/net/ethernet/smsc/smc91x.c#L1490">1490</a>         if (<a href="ident?i=lp">lp</a>-&gt;phy_type == 0)
<a name="L1491" href="source/drivers/net/ethernet/smsc/smc91x.c#L1491">1491</a>                 <a href="ident?i=lp">lp</a>-&gt;tcr_cur_mode |= <a href="ident?i=TCR_MON_CSN">TCR_MON_CSN</a>;
<a name="L1492" href="source/drivers/net/ethernet/smsc/smc91x.c#L1492">1492</a> 
<a name="L1493" href="source/drivers/net/ethernet/smsc/smc91x.c#L1493">1493</a>         <b><i>/* reset the hardware */</i></b>
<a name="L1494" href="source/drivers/net/ethernet/smsc/smc91x.c#L1494">1494</a>         <a href="ident?i=smc_reset">smc_reset</a>(<a href="ident?i=dev">dev</a>);
<a name="L1495" href="source/drivers/net/ethernet/smsc/smc91x.c#L1495">1495</a>         <a href="ident?i=smc_enable">smc_enable</a>(<a href="ident?i=dev">dev</a>);
<a name="L1496" href="source/drivers/net/ethernet/smsc/smc91x.c#L1496">1496</a> 
<a name="L1497" href="source/drivers/net/ethernet/smsc/smc91x.c#L1497">1497</a>         <b><i>/* Configure the PHY, initialize the link state */</i></b>
<a name="L1498" href="source/drivers/net/ethernet/smsc/smc91x.c#L1498">1498</a>         if (<a href="ident?i=lp">lp</a>-&gt;phy_type != 0)
<a name="L1499" href="source/drivers/net/ethernet/smsc/smc91x.c#L1499">1499</a>                 <a href="ident?i=smc_phy_configure">smc_phy_configure</a>(&amp;<a href="ident?i=lp">lp</a>-&gt;phy_configure);
<a name="L1500" href="source/drivers/net/ethernet/smsc/smc91x.c#L1500">1500</a>         else {
<a name="L1501" href="source/drivers/net/ethernet/smsc/smc91x.c#L1501">1501</a>                 <a href="ident?i=spin_lock_irq">spin_lock_irq</a>(&amp;<a href="ident?i=lp">lp</a>-&gt;<a href="ident?i=lock">lock</a>);
<a name="L1502" href="source/drivers/net/ethernet/smsc/smc91x.c#L1502">1502</a>                 <a href="ident?i=smc_10bt_check_media">smc_10bt_check_media</a>(<a href="ident?i=dev">dev</a>, 1);
<a name="L1503" href="source/drivers/net/ethernet/smsc/smc91x.c#L1503">1503</a>                 <a href="ident?i=spin_unlock_irq">spin_unlock_irq</a>(&amp;<a href="ident?i=lp">lp</a>-&gt;<a href="ident?i=lock">lock</a>);
<a name="L1504" href="source/drivers/net/ethernet/smsc/smc91x.c#L1504">1504</a>         }
<a name="L1505" href="source/drivers/net/ethernet/smsc/smc91x.c#L1505">1505</a> 
<a name="L1506" href="source/drivers/net/ethernet/smsc/smc91x.c#L1506">1506</a>         <a href="ident?i=netif_start_queue">netif_start_queue</a>(<a href="ident?i=dev">dev</a>);
<a name="L1507" href="source/drivers/net/ethernet/smsc/smc91x.c#L1507">1507</a>         return 0;
<a name="L1508" href="source/drivers/net/ethernet/smsc/smc91x.c#L1508">1508</a> }
<a name="L1509" href="source/drivers/net/ethernet/smsc/smc91x.c#L1509">1509</a> 
<a name="L1510" href="source/drivers/net/ethernet/smsc/smc91x.c#L1510">1510</a> <b><i>/*</i></b>
<a name="L1511" href="source/drivers/net/ethernet/smsc/smc91x.c#L1511">1511</a> <b><i> * smc_close</i></b>
<a name="L1512" href="source/drivers/net/ethernet/smsc/smc91x.c#L1512">1512</a> <b><i> *</i></b>
<a name="L1513" href="source/drivers/net/ethernet/smsc/smc91x.c#L1513">1513</a> <b><i> * this makes the board clean up everything that it can</i></b>
<a name="L1514" href="source/drivers/net/ethernet/smsc/smc91x.c#L1514">1514</a> <b><i> * and not talk to the outside world.   Caused by</i></b>
<a name="L1515" href="source/drivers/net/ethernet/smsc/smc91x.c#L1515">1515</a> <b><i> * an 'ifconfig ethX down'</i></b>
<a name="L1516" href="source/drivers/net/ethernet/smsc/smc91x.c#L1516">1516</a> <b><i> */</i></b>
<a name="L1517" href="source/drivers/net/ethernet/smsc/smc91x.c#L1517">1517</a> static int <a href="ident?i=smc_close">smc_close</a>(struct <a href="ident?i=net_device">net_device</a> *<a href="ident?i=dev">dev</a>)
<a name="L1518" href="source/drivers/net/ethernet/smsc/smc91x.c#L1518">1518</a> {
<a name="L1519" href="source/drivers/net/ethernet/smsc/smc91x.c#L1519">1519</a>         struct <a href="ident?i=smc_local">smc_local</a> *<a href="ident?i=lp">lp</a> = <a href="ident?i=netdev_priv">netdev_priv</a>(<a href="ident?i=dev">dev</a>);
<a name="L1520" href="source/drivers/net/ethernet/smsc/smc91x.c#L1520">1520</a> 
<a name="L1521" href="source/drivers/net/ethernet/smsc/smc91x.c#L1521">1521</a>         <a href="ident?i=DBG">DBG</a>(2, <a href="ident?i=dev">dev</a>, <i>"%s\n"</i>, <a href="ident?i=__func__">__func__</a>);
<a name="L1522" href="source/drivers/net/ethernet/smsc/smc91x.c#L1522">1522</a> 
<a name="L1523" href="source/drivers/net/ethernet/smsc/smc91x.c#L1523">1523</a>         <a href="ident?i=netif_stop_queue">netif_stop_queue</a>(<a href="ident?i=dev">dev</a>);
<a name="L1524" href="source/drivers/net/ethernet/smsc/smc91x.c#L1524">1524</a>         <a href="ident?i=netif_carrier_off">netif_carrier_off</a>(<a href="ident?i=dev">dev</a>);
<a name="L1525" href="source/drivers/net/ethernet/smsc/smc91x.c#L1525">1525</a> 
<a name="L1526" href="source/drivers/net/ethernet/smsc/smc91x.c#L1526">1526</a>         <b><i>/* clear everything */</i></b>
<a name="L1527" href="source/drivers/net/ethernet/smsc/smc91x.c#L1527">1527</a>         <a href="ident?i=smc_shutdown">smc_shutdown</a>(<a href="ident?i=dev">dev</a>);
<a name="L1528" href="source/drivers/net/ethernet/smsc/smc91x.c#L1528">1528</a>         <a href="ident?i=tasklet_kill">tasklet_kill</a>(&amp;<a href="ident?i=lp">lp</a>-&gt;tx_task);
<a name="L1529" href="source/drivers/net/ethernet/smsc/smc91x.c#L1529">1529</a>         <a href="ident?i=smc_phy_powerdown">smc_phy_powerdown</a>(<a href="ident?i=dev">dev</a>);
<a name="L1530" href="source/drivers/net/ethernet/smsc/smc91x.c#L1530">1530</a>         return 0;
<a name="L1531" href="source/drivers/net/ethernet/smsc/smc91x.c#L1531">1531</a> }
<a name="L1532" href="source/drivers/net/ethernet/smsc/smc91x.c#L1532">1532</a> 
<a name="L1533" href="source/drivers/net/ethernet/smsc/smc91x.c#L1533">1533</a> <b><i>/*</i></b>
<a name="L1534" href="source/drivers/net/ethernet/smsc/smc91x.c#L1534">1534</a> <b><i> * Ethtool support</i></b>
<a name="L1535" href="source/drivers/net/ethernet/smsc/smc91x.c#L1535">1535</a> <b><i> */</i></b>
<a name="L1536" href="source/drivers/net/ethernet/smsc/smc91x.c#L1536">1536</a> static int
<a name="L1537" href="source/drivers/net/ethernet/smsc/smc91x.c#L1537">1537</a> <a href="ident?i=smc_ethtool_getsettings">smc_ethtool_getsettings</a>(struct <a href="ident?i=net_device">net_device</a> *<a href="ident?i=dev">dev</a>, struct <a href="ident?i=ethtool_cmd">ethtool_cmd</a> *<a href="ident?i=cmd">cmd</a>)
<a name="L1538" href="source/drivers/net/ethernet/smsc/smc91x.c#L1538">1538</a> {
<a name="L1539" href="source/drivers/net/ethernet/smsc/smc91x.c#L1539">1539</a>         struct <a href="ident?i=smc_local">smc_local</a> *<a href="ident?i=lp">lp</a> = <a href="ident?i=netdev_priv">netdev_priv</a>(<a href="ident?i=dev">dev</a>);
<a name="L1540" href="source/drivers/net/ethernet/smsc/smc91x.c#L1540">1540</a>         int <a href="ident?i=ret">ret</a>;
<a name="L1541" href="source/drivers/net/ethernet/smsc/smc91x.c#L1541">1541</a> 
<a name="L1542" href="source/drivers/net/ethernet/smsc/smc91x.c#L1542">1542</a>         <a href="ident?i=cmd">cmd</a>-&gt;maxtxpkt = 1;
<a name="L1543" href="source/drivers/net/ethernet/smsc/smc91x.c#L1543">1543</a>         <a href="ident?i=cmd">cmd</a>-&gt;maxrxpkt = 1;
<a name="L1544" href="source/drivers/net/ethernet/smsc/smc91x.c#L1544">1544</a> 
<a name="L1545" href="source/drivers/net/ethernet/smsc/smc91x.c#L1545">1545</a>         if (<a href="ident?i=lp">lp</a>-&gt;phy_type != 0) {
<a name="L1546" href="source/drivers/net/ethernet/smsc/smc91x.c#L1546">1546</a>                 <a href="ident?i=spin_lock_irq">spin_lock_irq</a>(&amp;<a href="ident?i=lp">lp</a>-&gt;<a href="ident?i=lock">lock</a>);
<a name="L1547" href="source/drivers/net/ethernet/smsc/smc91x.c#L1547">1547</a>                 <a href="ident?i=ret">ret</a> = <a href="ident?i=mii_ethtool_gset">mii_ethtool_gset</a>(&amp;<a href="ident?i=lp">lp</a>-&gt;mii, <a href="ident?i=cmd">cmd</a>);
<a name="L1548" href="source/drivers/net/ethernet/smsc/smc91x.c#L1548">1548</a>                 <a href="ident?i=spin_unlock_irq">spin_unlock_irq</a>(&amp;<a href="ident?i=lp">lp</a>-&gt;<a href="ident?i=lock">lock</a>);
<a name="L1549" href="source/drivers/net/ethernet/smsc/smc91x.c#L1549">1549</a>         } else {
<a name="L1550" href="source/drivers/net/ethernet/smsc/smc91x.c#L1550">1550</a>                 <a href="ident?i=cmd">cmd</a>-&gt;<a href="ident?i=supported">supported</a> = <a href="ident?i=SUPPORTED_10baseT_Half">SUPPORTED_10baseT_Half</a> |
<a name="L1551" href="source/drivers/net/ethernet/smsc/smc91x.c#L1551">1551</a>                                  <a href="ident?i=SUPPORTED_10baseT_Full">SUPPORTED_10baseT_Full</a> |
<a name="L1552" href="source/drivers/net/ethernet/smsc/smc91x.c#L1552">1552</a>                                  <a href="ident?i=SUPPORTED_TP">SUPPORTED_TP</a> | <a href="ident?i=SUPPORTED_AUI">SUPPORTED_AUI</a>;
<a name="L1553" href="source/drivers/net/ethernet/smsc/smc91x.c#L1553">1553</a> 
<a name="L1554" href="source/drivers/net/ethernet/smsc/smc91x.c#L1554">1554</a>                 if (<a href="ident?i=lp">lp</a>-&gt;ctl_rspeed == 10)
<a name="L1555" href="source/drivers/net/ethernet/smsc/smc91x.c#L1555">1555</a>                         <a href="ident?i=ethtool_cmd_speed_set">ethtool_cmd_speed_set</a>(<a href="ident?i=cmd">cmd</a>, <a href="ident?i=SPEED_10">SPEED_10</a>);
<a name="L1556" href="source/drivers/net/ethernet/smsc/smc91x.c#L1556">1556</a>                 else if (<a href="ident?i=lp">lp</a>-&gt;ctl_rspeed == 100)
<a name="L1557" href="source/drivers/net/ethernet/smsc/smc91x.c#L1557">1557</a>                         <a href="ident?i=ethtool_cmd_speed_set">ethtool_cmd_speed_set</a>(<a href="ident?i=cmd">cmd</a>, <a href="ident?i=SPEED_100">SPEED_100</a>);
<a name="L1558" href="source/drivers/net/ethernet/smsc/smc91x.c#L1558">1558</a> 
<a name="L1559" href="source/drivers/net/ethernet/smsc/smc91x.c#L1559">1559</a>                 <a href="ident?i=cmd">cmd</a>-&gt;autoneg = <a href="ident?i=AUTONEG_DISABLE">AUTONEG_DISABLE</a>;
<a name="L1560" href="source/drivers/net/ethernet/smsc/smc91x.c#L1560">1560</a>                 <a href="ident?i=cmd">cmd</a>-&gt;<a href="ident?i=transceiver">transceiver</a> = <a href="ident?i=XCVR_INTERNAL">XCVR_INTERNAL</a>;
<a name="L1561" href="source/drivers/net/ethernet/smsc/smc91x.c#L1561">1561</a>                 <a href="ident?i=cmd">cmd</a>-&gt;<a href="ident?i=port">port</a> = 0;
<a name="L1562" href="source/drivers/net/ethernet/smsc/smc91x.c#L1562">1562</a>                 <a href="ident?i=cmd">cmd</a>-&gt;<a href="ident?i=duplex">duplex</a> = <a href="ident?i=lp">lp</a>-&gt;tcr_cur_mode &amp; <a href="ident?i=TCR_SWFDUP">TCR_SWFDUP</a> ? <a href="ident?i=DUPLEX_FULL">DUPLEX_FULL</a> : <a href="ident?i=DUPLEX_HALF">DUPLEX_HALF</a>;
<a name="L1563" href="source/drivers/net/ethernet/smsc/smc91x.c#L1563">1563</a> 
<a name="L1564" href="source/drivers/net/ethernet/smsc/smc91x.c#L1564">1564</a>                 <a href="ident?i=ret">ret</a> = 0;
<a name="L1565" href="source/drivers/net/ethernet/smsc/smc91x.c#L1565">1565</a>         }
<a name="L1566" href="source/drivers/net/ethernet/smsc/smc91x.c#L1566">1566</a> 
<a name="L1567" href="source/drivers/net/ethernet/smsc/smc91x.c#L1567">1567</a>         return <a href="ident?i=ret">ret</a>;
<a name="L1568" href="source/drivers/net/ethernet/smsc/smc91x.c#L1568">1568</a> }
<a name="L1569" href="source/drivers/net/ethernet/smsc/smc91x.c#L1569">1569</a> 
<a name="L1570" href="source/drivers/net/ethernet/smsc/smc91x.c#L1570">1570</a> static int
<a name="L1571" href="source/drivers/net/ethernet/smsc/smc91x.c#L1571">1571</a> <a href="ident?i=smc_ethtool_setsettings">smc_ethtool_setsettings</a>(struct <a href="ident?i=net_device">net_device</a> *<a href="ident?i=dev">dev</a>, struct <a href="ident?i=ethtool_cmd">ethtool_cmd</a> *<a href="ident?i=cmd">cmd</a>)
<a name="L1572" href="source/drivers/net/ethernet/smsc/smc91x.c#L1572">1572</a> {
<a name="L1573" href="source/drivers/net/ethernet/smsc/smc91x.c#L1573">1573</a>         struct <a href="ident?i=smc_local">smc_local</a> *<a href="ident?i=lp">lp</a> = <a href="ident?i=netdev_priv">netdev_priv</a>(<a href="ident?i=dev">dev</a>);
<a name="L1574" href="source/drivers/net/ethernet/smsc/smc91x.c#L1574">1574</a>         int <a href="ident?i=ret">ret</a>;
<a name="L1575" href="source/drivers/net/ethernet/smsc/smc91x.c#L1575">1575</a> 
<a name="L1576" href="source/drivers/net/ethernet/smsc/smc91x.c#L1576">1576</a>         if (<a href="ident?i=lp">lp</a>-&gt;phy_type != 0) {
<a name="L1577" href="source/drivers/net/ethernet/smsc/smc91x.c#L1577">1577</a>                 <a href="ident?i=spin_lock_irq">spin_lock_irq</a>(&amp;<a href="ident?i=lp">lp</a>-&gt;<a href="ident?i=lock">lock</a>);
<a name="L1578" href="source/drivers/net/ethernet/smsc/smc91x.c#L1578">1578</a>                 <a href="ident?i=ret">ret</a> = <a href="ident?i=mii_ethtool_sset">mii_ethtool_sset</a>(&amp;<a href="ident?i=lp">lp</a>-&gt;mii, <a href="ident?i=cmd">cmd</a>);
<a name="L1579" href="source/drivers/net/ethernet/smsc/smc91x.c#L1579">1579</a>                 <a href="ident?i=spin_unlock_irq">spin_unlock_irq</a>(&amp;<a href="ident?i=lp">lp</a>-&gt;<a href="ident?i=lock">lock</a>);
<a name="L1580" href="source/drivers/net/ethernet/smsc/smc91x.c#L1580">1580</a>         } else {
<a name="L1581" href="source/drivers/net/ethernet/smsc/smc91x.c#L1581">1581</a>                 if (<a href="ident?i=cmd">cmd</a>-&gt;autoneg != <a href="ident?i=AUTONEG_DISABLE">AUTONEG_DISABLE</a> ||
<a name="L1582" href="source/drivers/net/ethernet/smsc/smc91x.c#L1582">1582</a>                     <a href="ident?i=cmd">cmd</a>-&gt;<a href="ident?i=speed">speed</a> != <a href="ident?i=SPEED_10">SPEED_10</a> ||
<a name="L1583" href="source/drivers/net/ethernet/smsc/smc91x.c#L1583">1583</a>                     (<a href="ident?i=cmd">cmd</a>-&gt;<a href="ident?i=duplex">duplex</a> != <a href="ident?i=DUPLEX_HALF">DUPLEX_HALF</a> &amp;&amp; <a href="ident?i=cmd">cmd</a>-&gt;<a href="ident?i=duplex">duplex</a> != <a href="ident?i=DUPLEX_FULL">DUPLEX_FULL</a>) ||
<a name="L1584" href="source/drivers/net/ethernet/smsc/smc91x.c#L1584">1584</a>                     (<a href="ident?i=cmd">cmd</a>-&gt;<a href="ident?i=port">port</a> != <a href="ident?i=PORT_TP">PORT_TP</a> &amp;&amp; <a href="ident?i=cmd">cmd</a>-&gt;<a href="ident?i=port">port</a> != <a href="ident?i=PORT_AUI">PORT_AUI</a>))
<a name="L1585" href="source/drivers/net/ethernet/smsc/smc91x.c#L1585">1585</a>                         return -<a href="ident?i=EINVAL">EINVAL</a>;
<a name="L1586" href="source/drivers/net/ethernet/smsc/smc91x.c#L1586">1586</a> 
<a name="L1587" href="source/drivers/net/ethernet/smsc/smc91x.c#L1587">1587</a> <b><i>//              lp-&gt;port = cmd-&gt;port;</i></b>
<a name="L1588" href="source/drivers/net/ethernet/smsc/smc91x.c#L1588">1588</a> <b><i></i></b>                <a href="ident?i=lp">lp</a>-&gt;ctl_rfduplx = <a href="ident?i=cmd">cmd</a>-&gt;<a href="ident?i=duplex">duplex</a> == <a href="ident?i=DUPLEX_FULL">DUPLEX_FULL</a>;
<a name="L1589" href="source/drivers/net/ethernet/smsc/smc91x.c#L1589">1589</a> 
<a name="L1590" href="source/drivers/net/ethernet/smsc/smc91x.c#L1590">1590</a> <b><i>//              if (netif_running(dev))</i></b>
<a name="L1591" href="source/drivers/net/ethernet/smsc/smc91x.c#L1591">1591</a> <b><i></i></b><b><i>//                      smc_set_port(dev);</i></b>
<a name="L1592" href="source/drivers/net/ethernet/smsc/smc91x.c#L1592">1592</a> <b><i></i></b>
<a name="L1593" href="source/drivers/net/ethernet/smsc/smc91x.c#L1593">1593</a>                 <a href="ident?i=ret">ret</a> = 0;
<a name="L1594" href="source/drivers/net/ethernet/smsc/smc91x.c#L1594">1594</a>         }
<a name="L1595" href="source/drivers/net/ethernet/smsc/smc91x.c#L1595">1595</a> 
<a name="L1596" href="source/drivers/net/ethernet/smsc/smc91x.c#L1596">1596</a>         return <a href="ident?i=ret">ret</a>;
<a name="L1597" href="source/drivers/net/ethernet/smsc/smc91x.c#L1597">1597</a> }
<a name="L1598" href="source/drivers/net/ethernet/smsc/smc91x.c#L1598">1598</a> 
<a name="L1599" href="source/drivers/net/ethernet/smsc/smc91x.c#L1599">1599</a> static void
<a name="L1600" href="source/drivers/net/ethernet/smsc/smc91x.c#L1600">1600</a> <a href="ident?i=smc_ethtool_getdrvinfo">smc_ethtool_getdrvinfo</a>(struct <a href="ident?i=net_device">net_device</a> *<a href="ident?i=dev">dev</a>, struct <a href="ident?i=ethtool_drvinfo">ethtool_drvinfo</a> *<a href="ident?i=info">info</a>)
<a name="L1601" href="source/drivers/net/ethernet/smsc/smc91x.c#L1601">1601</a> {
<a name="L1602" href="source/drivers/net/ethernet/smsc/smc91x.c#L1602">1602</a>         <a href="ident?i=strlcpy">strlcpy</a>(<a href="ident?i=info">info</a>-&gt;<a href="ident?i=driver">driver</a>, <a href="ident?i=CARDNAME">CARDNAME</a>, sizeof(<a href="ident?i=info">info</a>-&gt;<a href="ident?i=driver">driver</a>));
<a name="L1603" href="source/drivers/net/ethernet/smsc/smc91x.c#L1603">1603</a>         <a href="ident?i=strlcpy">strlcpy</a>(<a href="ident?i=info">info</a>-&gt;<a href="ident?i=version">version</a>, <a href="ident?i=version">version</a>, sizeof(<a href="ident?i=info">info</a>-&gt;<a href="ident?i=version">version</a>));
<a name="L1604" href="source/drivers/net/ethernet/smsc/smc91x.c#L1604">1604</a>         <a href="ident?i=strlcpy">strlcpy</a>(<a href="ident?i=info">info</a>-&gt;<a href="ident?i=bus_info">bus_info</a>, <a href="ident?i=dev_name">dev_name</a>(<a href="ident?i=dev">dev</a>-&gt;<a href="ident?i=dev">dev</a>.<a href="ident?i=parent">parent</a>),
<a name="L1605" href="source/drivers/net/ethernet/smsc/smc91x.c#L1605">1605</a>                 sizeof(<a href="ident?i=info">info</a>-&gt;<a href="ident?i=bus_info">bus_info</a>));
<a name="L1606" href="source/drivers/net/ethernet/smsc/smc91x.c#L1606">1606</a> }
<a name="L1607" href="source/drivers/net/ethernet/smsc/smc91x.c#L1607">1607</a> 
<a name="L1608" href="source/drivers/net/ethernet/smsc/smc91x.c#L1608">1608</a> static int <a href="ident?i=smc_ethtool_nwayreset">smc_ethtool_nwayreset</a>(struct <a href="ident?i=net_device">net_device</a> *<a href="ident?i=dev">dev</a>)
<a name="L1609" href="source/drivers/net/ethernet/smsc/smc91x.c#L1609">1609</a> {
<a name="L1610" href="source/drivers/net/ethernet/smsc/smc91x.c#L1610">1610</a>         struct <a href="ident?i=smc_local">smc_local</a> *<a href="ident?i=lp">lp</a> = <a href="ident?i=netdev_priv">netdev_priv</a>(<a href="ident?i=dev">dev</a>);
<a name="L1611" href="source/drivers/net/ethernet/smsc/smc91x.c#L1611">1611</a>         int <a href="ident?i=ret">ret</a> = -<a href="ident?i=EINVAL">EINVAL</a>;
<a name="L1612" href="source/drivers/net/ethernet/smsc/smc91x.c#L1612">1612</a> 
<a name="L1613" href="source/drivers/net/ethernet/smsc/smc91x.c#L1613">1613</a>         if (<a href="ident?i=lp">lp</a>-&gt;phy_type != 0) {
<a name="L1614" href="source/drivers/net/ethernet/smsc/smc91x.c#L1614">1614</a>                 <a href="ident?i=spin_lock_irq">spin_lock_irq</a>(&amp;<a href="ident?i=lp">lp</a>-&gt;<a href="ident?i=lock">lock</a>);
<a name="L1615" href="source/drivers/net/ethernet/smsc/smc91x.c#L1615">1615</a>                 <a href="ident?i=ret">ret</a> = <a href="ident?i=mii_nway_restart">mii_nway_restart</a>(&amp;<a href="ident?i=lp">lp</a>-&gt;mii);
<a name="L1616" href="source/drivers/net/ethernet/smsc/smc91x.c#L1616">1616</a>                 <a href="ident?i=spin_unlock_irq">spin_unlock_irq</a>(&amp;<a href="ident?i=lp">lp</a>-&gt;<a href="ident?i=lock">lock</a>);
<a name="L1617" href="source/drivers/net/ethernet/smsc/smc91x.c#L1617">1617</a>         }
<a name="L1618" href="source/drivers/net/ethernet/smsc/smc91x.c#L1618">1618</a> 
<a name="L1619" href="source/drivers/net/ethernet/smsc/smc91x.c#L1619">1619</a>         return <a href="ident?i=ret">ret</a>;
<a name="L1620" href="source/drivers/net/ethernet/smsc/smc91x.c#L1620">1620</a> }
<a name="L1621" href="source/drivers/net/ethernet/smsc/smc91x.c#L1621">1621</a> 
<a name="L1622" href="source/drivers/net/ethernet/smsc/smc91x.c#L1622">1622</a> static <a href="ident?i=u32">u32</a> <a href="ident?i=smc_ethtool_getmsglevel">smc_ethtool_getmsglevel</a>(struct <a href="ident?i=net_device">net_device</a> *<a href="ident?i=dev">dev</a>)
<a name="L1623" href="source/drivers/net/ethernet/smsc/smc91x.c#L1623">1623</a> {
<a name="L1624" href="source/drivers/net/ethernet/smsc/smc91x.c#L1624">1624</a>         struct <a href="ident?i=smc_local">smc_local</a> *<a href="ident?i=lp">lp</a> = <a href="ident?i=netdev_priv">netdev_priv</a>(<a href="ident?i=dev">dev</a>);
<a name="L1625" href="source/drivers/net/ethernet/smsc/smc91x.c#L1625">1625</a>         return <a href="ident?i=lp">lp</a>-&gt;<a href="ident?i=msg_enable">msg_enable</a>;
<a name="L1626" href="source/drivers/net/ethernet/smsc/smc91x.c#L1626">1626</a> }
<a name="L1627" href="source/drivers/net/ethernet/smsc/smc91x.c#L1627">1627</a> 
<a name="L1628" href="source/drivers/net/ethernet/smsc/smc91x.c#L1628">1628</a> static void <a href="ident?i=smc_ethtool_setmsglevel">smc_ethtool_setmsglevel</a>(struct <a href="ident?i=net_device">net_device</a> *<a href="ident?i=dev">dev</a>, <a href="ident?i=u32">u32</a> <a href="ident?i=level">level</a>)
<a name="L1629" href="source/drivers/net/ethernet/smsc/smc91x.c#L1629">1629</a> {
<a name="L1630" href="source/drivers/net/ethernet/smsc/smc91x.c#L1630">1630</a>         struct <a href="ident?i=smc_local">smc_local</a> *<a href="ident?i=lp">lp</a> = <a href="ident?i=netdev_priv">netdev_priv</a>(<a href="ident?i=dev">dev</a>);
<a name="L1631" href="source/drivers/net/ethernet/smsc/smc91x.c#L1631">1631</a>         <a href="ident?i=lp">lp</a>-&gt;<a href="ident?i=msg_enable">msg_enable</a> = <a href="ident?i=level">level</a>;
<a name="L1632" href="source/drivers/net/ethernet/smsc/smc91x.c#L1632">1632</a> }
<a name="L1633" href="source/drivers/net/ethernet/smsc/smc91x.c#L1633">1633</a> 
<a name="L1634" href="source/drivers/net/ethernet/smsc/smc91x.c#L1634">1634</a> static int <a href="ident?i=smc_write_eeprom_word">smc_write_eeprom_word</a>(struct <a href="ident?i=net_device">net_device</a> *<a href="ident?i=dev">dev</a>, <a href="ident?i=u16">u16</a> <a href="ident?i=addr">addr</a>, <a href="ident?i=u16">u16</a> <a href="ident?i=word">word</a>)
<a name="L1635" href="source/drivers/net/ethernet/smsc/smc91x.c#L1635">1635</a> {
<a name="L1636" href="source/drivers/net/ethernet/smsc/smc91x.c#L1636">1636</a>         <a href="ident?i=u16">u16</a> <a href="ident?i=ctl">ctl</a>;
<a name="L1637" href="source/drivers/net/ethernet/smsc/smc91x.c#L1637">1637</a>         struct <a href="ident?i=smc_local">smc_local</a> *<a href="ident?i=lp">lp</a> = <a href="ident?i=netdev_priv">netdev_priv</a>(<a href="ident?i=dev">dev</a>);
<a name="L1638" href="source/drivers/net/ethernet/smsc/smc91x.c#L1638">1638</a>         void <a href="ident?i=__iomem">__iomem</a> *<a href="ident?i=ioaddr">ioaddr</a> = <a href="ident?i=lp">lp</a>-&gt;<a href="ident?i=base">base</a>;
<a name="L1639" href="source/drivers/net/ethernet/smsc/smc91x.c#L1639">1639</a> 
<a name="L1640" href="source/drivers/net/ethernet/smsc/smc91x.c#L1640">1640</a>         <a href="ident?i=spin_lock_irq">spin_lock_irq</a>(&amp;<a href="ident?i=lp">lp</a>-&gt;<a href="ident?i=lock">lock</a>);
<a name="L1641" href="source/drivers/net/ethernet/smsc/smc91x.c#L1641">1641</a>         <b><i>/* load word into GP register */</i></b>
<a name="L1642" href="source/drivers/net/ethernet/smsc/smc91x.c#L1642">1642</a>         <a href="ident?i=SMC_SELECT_BANK">SMC_SELECT_BANK</a>(<a href="ident?i=lp">lp</a>, 1);
<a name="L1643" href="source/drivers/net/ethernet/smsc/smc91x.c#L1643">1643</a>         <a href="ident?i=SMC_SET_GP">SMC_SET_GP</a>(<a href="ident?i=lp">lp</a>, <a href="ident?i=word">word</a>);
<a name="L1644" href="source/drivers/net/ethernet/smsc/smc91x.c#L1644">1644</a>         <b><i>/* set the address to put the data in EEPROM */</i></b>
<a name="L1645" href="source/drivers/net/ethernet/smsc/smc91x.c#L1645">1645</a>         <a href="ident?i=SMC_SELECT_BANK">SMC_SELECT_BANK</a>(<a href="ident?i=lp">lp</a>, 2);
<a name="L1646" href="source/drivers/net/ethernet/smsc/smc91x.c#L1646">1646</a>         <a href="ident?i=SMC_SET_PTR">SMC_SET_PTR</a>(<a href="ident?i=lp">lp</a>, <a href="ident?i=addr">addr</a>);
<a name="L1647" href="source/drivers/net/ethernet/smsc/smc91x.c#L1647">1647</a>         <b><i>/* tell it to write */</i></b>
<a name="L1648" href="source/drivers/net/ethernet/smsc/smc91x.c#L1648">1648</a>         <a href="ident?i=SMC_SELECT_BANK">SMC_SELECT_BANK</a>(<a href="ident?i=lp">lp</a>, 1);
<a name="L1649" href="source/drivers/net/ethernet/smsc/smc91x.c#L1649">1649</a>         <a href="ident?i=ctl">ctl</a> = <a href="ident?i=SMC_GET_CTL">SMC_GET_CTL</a>(<a href="ident?i=lp">lp</a>);
<a name="L1650" href="source/drivers/net/ethernet/smsc/smc91x.c#L1650">1650</a>         <a href="ident?i=SMC_SET_CTL">SMC_SET_CTL</a>(<a href="ident?i=lp">lp</a>, <a href="ident?i=ctl">ctl</a> | (<a href="ident?i=CTL_EEPROM_SELECT">CTL_EEPROM_SELECT</a> | <a href="ident?i=CTL_STORE">CTL_STORE</a>));
<a name="L1651" href="source/drivers/net/ethernet/smsc/smc91x.c#L1651">1651</a>         <b><i>/* wait for it to finish */</i></b>
<a name="L1652" href="source/drivers/net/ethernet/smsc/smc91x.c#L1652">1652</a>         do {
<a name="L1653" href="source/drivers/net/ethernet/smsc/smc91x.c#L1653">1653</a>                 <a href="ident?i=udelay">udelay</a>(1);
<a name="L1654" href="source/drivers/net/ethernet/smsc/smc91x.c#L1654">1654</a>         } while (<a href="ident?i=SMC_GET_CTL">SMC_GET_CTL</a>(<a href="ident?i=lp">lp</a>) &amp; <a href="ident?i=CTL_STORE">CTL_STORE</a>);
<a name="L1655" href="source/drivers/net/ethernet/smsc/smc91x.c#L1655">1655</a>         <b><i>/* clean up */</i></b>
<a name="L1656" href="source/drivers/net/ethernet/smsc/smc91x.c#L1656">1656</a>         <a href="ident?i=SMC_SET_CTL">SMC_SET_CTL</a>(<a href="ident?i=lp">lp</a>, <a href="ident?i=ctl">ctl</a>);
<a name="L1657" href="source/drivers/net/ethernet/smsc/smc91x.c#L1657">1657</a>         <a href="ident?i=SMC_SELECT_BANK">SMC_SELECT_BANK</a>(<a href="ident?i=lp">lp</a>, 2);
<a name="L1658" href="source/drivers/net/ethernet/smsc/smc91x.c#L1658">1658</a>         <a href="ident?i=spin_unlock_irq">spin_unlock_irq</a>(&amp;<a href="ident?i=lp">lp</a>-&gt;<a href="ident?i=lock">lock</a>);
<a name="L1659" href="source/drivers/net/ethernet/smsc/smc91x.c#L1659">1659</a>         return 0;
<a name="L1660" href="source/drivers/net/ethernet/smsc/smc91x.c#L1660">1660</a> }
<a name="L1661" href="source/drivers/net/ethernet/smsc/smc91x.c#L1661">1661</a> 
<a name="L1662" href="source/drivers/net/ethernet/smsc/smc91x.c#L1662">1662</a> static int <a href="ident?i=smc_read_eeprom_word">smc_read_eeprom_word</a>(struct <a href="ident?i=net_device">net_device</a> *<a href="ident?i=dev">dev</a>, <a href="ident?i=u16">u16</a> <a href="ident?i=addr">addr</a>, <a href="ident?i=u16">u16</a> *<a href="ident?i=word">word</a>)
<a name="L1663" href="source/drivers/net/ethernet/smsc/smc91x.c#L1663">1663</a> {
<a name="L1664" href="source/drivers/net/ethernet/smsc/smc91x.c#L1664">1664</a>         <a href="ident?i=u16">u16</a> <a href="ident?i=ctl">ctl</a>;
<a name="L1665" href="source/drivers/net/ethernet/smsc/smc91x.c#L1665">1665</a>         struct <a href="ident?i=smc_local">smc_local</a> *<a href="ident?i=lp">lp</a> = <a href="ident?i=netdev_priv">netdev_priv</a>(<a href="ident?i=dev">dev</a>);
<a name="L1666" href="source/drivers/net/ethernet/smsc/smc91x.c#L1666">1666</a>         void <a href="ident?i=__iomem">__iomem</a> *<a href="ident?i=ioaddr">ioaddr</a> = <a href="ident?i=lp">lp</a>-&gt;<a href="ident?i=base">base</a>;
<a name="L1667" href="source/drivers/net/ethernet/smsc/smc91x.c#L1667">1667</a> 
<a name="L1668" href="source/drivers/net/ethernet/smsc/smc91x.c#L1668">1668</a>         <a href="ident?i=spin_lock_irq">spin_lock_irq</a>(&amp;<a href="ident?i=lp">lp</a>-&gt;<a href="ident?i=lock">lock</a>);
<a name="L1669" href="source/drivers/net/ethernet/smsc/smc91x.c#L1669">1669</a>         <b><i>/* set the EEPROM address to get the data from */</i></b>
<a name="L1670" href="source/drivers/net/ethernet/smsc/smc91x.c#L1670">1670</a>         <a href="ident?i=SMC_SELECT_BANK">SMC_SELECT_BANK</a>(<a href="ident?i=lp">lp</a>, 2);
<a name="L1671" href="source/drivers/net/ethernet/smsc/smc91x.c#L1671">1671</a>         <a href="ident?i=SMC_SET_PTR">SMC_SET_PTR</a>(<a href="ident?i=lp">lp</a>, <a href="ident?i=addr">addr</a> | <a href="ident?i=PTR_READ">PTR_READ</a>);
<a name="L1672" href="source/drivers/net/ethernet/smsc/smc91x.c#L1672">1672</a>         <b><i>/* tell it to load */</i></b>
<a name="L1673" href="source/drivers/net/ethernet/smsc/smc91x.c#L1673">1673</a>         <a href="ident?i=SMC_SELECT_BANK">SMC_SELECT_BANK</a>(<a href="ident?i=lp">lp</a>, 1);
<a name="L1674" href="source/drivers/net/ethernet/smsc/smc91x.c#L1674">1674</a>         <a href="ident?i=SMC_SET_GP">SMC_SET_GP</a>(<a href="ident?i=lp">lp</a>, 0xffff); <b><i>/* init to known */</i></b>
<a name="L1675" href="source/drivers/net/ethernet/smsc/smc91x.c#L1675">1675</a>         <a href="ident?i=ctl">ctl</a> = <a href="ident?i=SMC_GET_CTL">SMC_GET_CTL</a>(<a href="ident?i=lp">lp</a>);
<a name="L1676" href="source/drivers/net/ethernet/smsc/smc91x.c#L1676">1676</a>         <a href="ident?i=SMC_SET_CTL">SMC_SET_CTL</a>(<a href="ident?i=lp">lp</a>, <a href="ident?i=ctl">ctl</a> | (<a href="ident?i=CTL_EEPROM_SELECT">CTL_EEPROM_SELECT</a> | <a href="ident?i=CTL_RELOAD">CTL_RELOAD</a>));
<a name="L1677" href="source/drivers/net/ethernet/smsc/smc91x.c#L1677">1677</a>         <b><i>/* wait for it to finish */</i></b>
<a name="L1678" href="source/drivers/net/ethernet/smsc/smc91x.c#L1678">1678</a>         do {
<a name="L1679" href="source/drivers/net/ethernet/smsc/smc91x.c#L1679">1679</a>                 <a href="ident?i=udelay">udelay</a>(1);
<a name="L1680" href="source/drivers/net/ethernet/smsc/smc91x.c#L1680">1680</a>         } while (<a href="ident?i=SMC_GET_CTL">SMC_GET_CTL</a>(<a href="ident?i=lp">lp</a>) &amp; <a href="ident?i=CTL_RELOAD">CTL_RELOAD</a>);
<a name="L1681" href="source/drivers/net/ethernet/smsc/smc91x.c#L1681">1681</a>         <b><i>/* read word from GP register */</i></b>
<a name="L1682" href="source/drivers/net/ethernet/smsc/smc91x.c#L1682">1682</a>         *<a href="ident?i=word">word</a> = <a href="ident?i=SMC_GET_GP">SMC_GET_GP</a>(<a href="ident?i=lp">lp</a>);
<a name="L1683" href="source/drivers/net/ethernet/smsc/smc91x.c#L1683">1683</a>         <b><i>/* clean up */</i></b>
<a name="L1684" href="source/drivers/net/ethernet/smsc/smc91x.c#L1684">1684</a>         <a href="ident?i=SMC_SET_CTL">SMC_SET_CTL</a>(<a href="ident?i=lp">lp</a>, <a href="ident?i=ctl">ctl</a>);
<a name="L1685" href="source/drivers/net/ethernet/smsc/smc91x.c#L1685">1685</a>         <a href="ident?i=SMC_SELECT_BANK">SMC_SELECT_BANK</a>(<a href="ident?i=lp">lp</a>, 2);
<a name="L1686" href="source/drivers/net/ethernet/smsc/smc91x.c#L1686">1686</a>         <a href="ident?i=spin_unlock_irq">spin_unlock_irq</a>(&amp;<a href="ident?i=lp">lp</a>-&gt;<a href="ident?i=lock">lock</a>);
<a name="L1687" href="source/drivers/net/ethernet/smsc/smc91x.c#L1687">1687</a>         return 0;
<a name="L1688" href="source/drivers/net/ethernet/smsc/smc91x.c#L1688">1688</a> }
<a name="L1689" href="source/drivers/net/ethernet/smsc/smc91x.c#L1689">1689</a> 
<a name="L1690" href="source/drivers/net/ethernet/smsc/smc91x.c#L1690">1690</a> static int <a href="ident?i=smc_ethtool_geteeprom_len">smc_ethtool_geteeprom_len</a>(struct <a href="ident?i=net_device">net_device</a> *<a href="ident?i=dev">dev</a>)
<a name="L1691" href="source/drivers/net/ethernet/smsc/smc91x.c#L1691">1691</a> {
<a name="L1692" href="source/drivers/net/ethernet/smsc/smc91x.c#L1692">1692</a>         return 0x23 * 2;
<a name="L1693" href="source/drivers/net/ethernet/smsc/smc91x.c#L1693">1693</a> }
<a name="L1694" href="source/drivers/net/ethernet/smsc/smc91x.c#L1694">1694</a> 
<a name="L1695" href="source/drivers/net/ethernet/smsc/smc91x.c#L1695">1695</a> static int <a href="ident?i=smc_ethtool_geteeprom">smc_ethtool_geteeprom</a>(struct <a href="ident?i=net_device">net_device</a> *<a href="ident?i=dev">dev</a>,
<a name="L1696" href="source/drivers/net/ethernet/smsc/smc91x.c#L1696">1696</a>                 struct <a href="ident?i=ethtool_eeprom">ethtool_eeprom</a> *<a href="ident?i=eeprom">eeprom</a>, <a href="ident?i=u8">u8</a> *<a href="ident?i=data">data</a>)
<a name="L1697" href="source/drivers/net/ethernet/smsc/smc91x.c#L1697">1697</a> {
<a name="L1698" href="source/drivers/net/ethernet/smsc/smc91x.c#L1698">1698</a>         int <a href="ident?i=i">i</a>;
<a name="L1699" href="source/drivers/net/ethernet/smsc/smc91x.c#L1699">1699</a>         int imax;
<a name="L1700" href="source/drivers/net/ethernet/smsc/smc91x.c#L1700">1700</a> 
<a name="L1701" href="source/drivers/net/ethernet/smsc/smc91x.c#L1701">1701</a>         <a href="ident?i=DBG">DBG</a>(1, <a href="ident?i=dev">dev</a>, <i>"Reading %d bytes at %d(0x%x)\n"</i>,
<a name="L1702" href="source/drivers/net/ethernet/smsc/smc91x.c#L1702">1702</a>                 <a href="ident?i=eeprom">eeprom</a>-&gt;<a href="ident?i=len">len</a>, <a href="ident?i=eeprom">eeprom</a>-&gt;<a href="ident?i=offset">offset</a>, <a href="ident?i=eeprom">eeprom</a>-&gt;<a href="ident?i=offset">offset</a>);
<a name="L1703" href="source/drivers/net/ethernet/smsc/smc91x.c#L1703">1703</a>         imax = <a href="ident?i=smc_ethtool_geteeprom_len">smc_ethtool_geteeprom_len</a>(<a href="ident?i=dev">dev</a>);
<a name="L1704" href="source/drivers/net/ethernet/smsc/smc91x.c#L1704">1704</a>         for (<a href="ident?i=i">i</a> = 0; <a href="ident?i=i">i</a> &lt; <a href="ident?i=eeprom">eeprom</a>-&gt;<a href="ident?i=len">len</a>; <a href="ident?i=i">i</a> += 2) {
<a name="L1705" href="source/drivers/net/ethernet/smsc/smc91x.c#L1705">1705</a>                 int <a href="ident?i=ret">ret</a>;
<a name="L1706" href="source/drivers/net/ethernet/smsc/smc91x.c#L1706">1706</a>                 <a href="ident?i=u16">u16</a> wbuf;
<a name="L1707" href="source/drivers/net/ethernet/smsc/smc91x.c#L1707">1707</a>                 int <a href="ident?i=offset">offset</a> = <a href="ident?i=i">i</a> + <a href="ident?i=eeprom">eeprom</a>-&gt;<a href="ident?i=offset">offset</a>;
<a name="L1708" href="source/drivers/net/ethernet/smsc/smc91x.c#L1708">1708</a>                 if (<a href="ident?i=offset">offset</a> &gt; imax)
<a name="L1709" href="source/drivers/net/ethernet/smsc/smc91x.c#L1709">1709</a>                         break;
<a name="L1710" href="source/drivers/net/ethernet/smsc/smc91x.c#L1710">1710</a>                 <a href="ident?i=ret">ret</a> = <a href="ident?i=smc_read_eeprom_word">smc_read_eeprom_word</a>(<a href="ident?i=dev">dev</a>, <a href="ident?i=offset">offset</a> &gt;&gt; 1, &amp;wbuf);
<a name="L1711" href="source/drivers/net/ethernet/smsc/smc91x.c#L1711">1711</a>                 if (<a href="ident?i=ret">ret</a> != 0)
<a name="L1712" href="source/drivers/net/ethernet/smsc/smc91x.c#L1712">1712</a>                         return <a href="ident?i=ret">ret</a>;
<a name="L1713" href="source/drivers/net/ethernet/smsc/smc91x.c#L1713">1713</a>                 <a href="ident?i=DBG">DBG</a>(2, <a href="ident?i=dev">dev</a>, <i>"Read 0x%x from 0x%x\n"</i>, wbuf, <a href="ident?i=offset">offset</a> &gt;&gt; 1);
<a name="L1714" href="source/drivers/net/ethernet/smsc/smc91x.c#L1714">1714</a>                 <a href="ident?i=data">data</a>[<a href="ident?i=i">i</a>] = (wbuf &gt;&gt; 8) &amp; 0xff;
<a name="L1715" href="source/drivers/net/ethernet/smsc/smc91x.c#L1715">1715</a>                 <a href="ident?i=data">data</a>[<a href="ident?i=i">i</a>+1] = wbuf &amp; 0xff;
<a name="L1716" href="source/drivers/net/ethernet/smsc/smc91x.c#L1716">1716</a>         }
<a name="L1717" href="source/drivers/net/ethernet/smsc/smc91x.c#L1717">1717</a>         return 0;
<a name="L1718" href="source/drivers/net/ethernet/smsc/smc91x.c#L1718">1718</a> }
<a name="L1719" href="source/drivers/net/ethernet/smsc/smc91x.c#L1719">1719</a> 
<a name="L1720" href="source/drivers/net/ethernet/smsc/smc91x.c#L1720">1720</a> static int <a href="ident?i=smc_ethtool_seteeprom">smc_ethtool_seteeprom</a>(struct <a href="ident?i=net_device">net_device</a> *<a href="ident?i=dev">dev</a>,
<a name="L1721" href="source/drivers/net/ethernet/smsc/smc91x.c#L1721">1721</a>                 struct <a href="ident?i=ethtool_eeprom">ethtool_eeprom</a> *<a href="ident?i=eeprom">eeprom</a>, <a href="ident?i=u8">u8</a> *<a href="ident?i=data">data</a>)
<a name="L1722" href="source/drivers/net/ethernet/smsc/smc91x.c#L1722">1722</a> {
<a name="L1723" href="source/drivers/net/ethernet/smsc/smc91x.c#L1723">1723</a>         int <a href="ident?i=i">i</a>;
<a name="L1724" href="source/drivers/net/ethernet/smsc/smc91x.c#L1724">1724</a>         int imax;
<a name="L1725" href="source/drivers/net/ethernet/smsc/smc91x.c#L1725">1725</a> 
<a name="L1726" href="source/drivers/net/ethernet/smsc/smc91x.c#L1726">1726</a>         <a href="ident?i=DBG">DBG</a>(1, <a href="ident?i=dev">dev</a>, <i>"Writing %d bytes to %d(0x%x)\n"</i>,
<a name="L1727" href="source/drivers/net/ethernet/smsc/smc91x.c#L1727">1727</a>             <a href="ident?i=eeprom">eeprom</a>-&gt;<a href="ident?i=len">len</a>, <a href="ident?i=eeprom">eeprom</a>-&gt;<a href="ident?i=offset">offset</a>, <a href="ident?i=eeprom">eeprom</a>-&gt;<a href="ident?i=offset">offset</a>);
<a name="L1728" href="source/drivers/net/ethernet/smsc/smc91x.c#L1728">1728</a>         imax = <a href="ident?i=smc_ethtool_geteeprom_len">smc_ethtool_geteeprom_len</a>(<a href="ident?i=dev">dev</a>);
<a name="L1729" href="source/drivers/net/ethernet/smsc/smc91x.c#L1729">1729</a>         for (<a href="ident?i=i">i</a> = 0; <a href="ident?i=i">i</a> &lt; <a href="ident?i=eeprom">eeprom</a>-&gt;<a href="ident?i=len">len</a>; <a href="ident?i=i">i</a> += 2) {
<a name="L1730" href="source/drivers/net/ethernet/smsc/smc91x.c#L1730">1730</a>                 int <a href="ident?i=ret">ret</a>;
<a name="L1731" href="source/drivers/net/ethernet/smsc/smc91x.c#L1731">1731</a>                 <a href="ident?i=u16">u16</a> wbuf;
<a name="L1732" href="source/drivers/net/ethernet/smsc/smc91x.c#L1732">1732</a>                 int <a href="ident?i=offset">offset</a> = <a href="ident?i=i">i</a> + <a href="ident?i=eeprom">eeprom</a>-&gt;<a href="ident?i=offset">offset</a>;
<a name="L1733" href="source/drivers/net/ethernet/smsc/smc91x.c#L1733">1733</a>                 if (<a href="ident?i=offset">offset</a> &gt; imax)
<a name="L1734" href="source/drivers/net/ethernet/smsc/smc91x.c#L1734">1734</a>                         break;
<a name="L1735" href="source/drivers/net/ethernet/smsc/smc91x.c#L1735">1735</a>                 wbuf = (<a href="ident?i=data">data</a>[<a href="ident?i=i">i</a>] &lt;&lt; 8) | <a href="ident?i=data">data</a>[<a href="ident?i=i">i</a> + 1];
<a name="L1736" href="source/drivers/net/ethernet/smsc/smc91x.c#L1736">1736</a>                 <a href="ident?i=DBG">DBG</a>(2, <a href="ident?i=dev">dev</a>, <i>"Writing 0x%x to 0x%x\n"</i>, wbuf, <a href="ident?i=offset">offset</a> &gt;&gt; 1);
<a name="L1737" href="source/drivers/net/ethernet/smsc/smc91x.c#L1737">1737</a>                 <a href="ident?i=ret">ret</a> = <a href="ident?i=smc_write_eeprom_word">smc_write_eeprom_word</a>(<a href="ident?i=dev">dev</a>, <a href="ident?i=offset">offset</a> &gt;&gt; 1, wbuf);
<a name="L1738" href="source/drivers/net/ethernet/smsc/smc91x.c#L1738">1738</a>                 if (<a href="ident?i=ret">ret</a> != 0)
<a name="L1739" href="source/drivers/net/ethernet/smsc/smc91x.c#L1739">1739</a>                         return <a href="ident?i=ret">ret</a>;
<a name="L1740" href="source/drivers/net/ethernet/smsc/smc91x.c#L1740">1740</a>         }
<a name="L1741" href="source/drivers/net/ethernet/smsc/smc91x.c#L1741">1741</a>         return 0;
<a name="L1742" href="source/drivers/net/ethernet/smsc/smc91x.c#L1742">1742</a> }
<a name="L1743" href="source/drivers/net/ethernet/smsc/smc91x.c#L1743">1743</a> 
<a name="L1744" href="source/drivers/net/ethernet/smsc/smc91x.c#L1744">1744</a> 
<a name="L1745" href="source/drivers/net/ethernet/smsc/smc91x.c#L1745">1745</a> static const struct <a href="ident?i=ethtool_ops">ethtool_ops</a> <a href="ident?i=smc_ethtool_ops">smc_ethtool_ops</a> = {
<a name="L1746" href="source/drivers/net/ethernet/smsc/smc91x.c#L1746">1746</a>         .<a href="ident?i=get_settings">get_settings</a>   = <a href="ident?i=smc_ethtool_getsettings">smc_ethtool_getsettings</a>,
<a name="L1747" href="source/drivers/net/ethernet/smsc/smc91x.c#L1747">1747</a>         .<a href="ident?i=set_settings">set_settings</a>   = <a href="ident?i=smc_ethtool_setsettings">smc_ethtool_setsettings</a>,
<a name="L1748" href="source/drivers/net/ethernet/smsc/smc91x.c#L1748">1748</a>         .<a href="ident?i=get_drvinfo">get_drvinfo</a>    = <a href="ident?i=smc_ethtool_getdrvinfo">smc_ethtool_getdrvinfo</a>,
<a name="L1749" href="source/drivers/net/ethernet/smsc/smc91x.c#L1749">1749</a> 
<a name="L1750" href="source/drivers/net/ethernet/smsc/smc91x.c#L1750">1750</a>         .<a href="ident?i=get_msglevel">get_msglevel</a>   = <a href="ident?i=smc_ethtool_getmsglevel">smc_ethtool_getmsglevel</a>,
<a name="L1751" href="source/drivers/net/ethernet/smsc/smc91x.c#L1751">1751</a>         .<a href="ident?i=set_msglevel">set_msglevel</a>   = <a href="ident?i=smc_ethtool_setmsglevel">smc_ethtool_setmsglevel</a>,
<a name="L1752" href="source/drivers/net/ethernet/smsc/smc91x.c#L1752">1752</a>         .<a href="ident?i=nway_reset">nway_reset</a>     = <a href="ident?i=smc_ethtool_nwayreset">smc_ethtool_nwayreset</a>,
<a name="L1753" href="source/drivers/net/ethernet/smsc/smc91x.c#L1753">1753</a>         .<a href="ident?i=get_link">get_link</a>       = <a href="ident?i=ethtool_op_get_link">ethtool_op_get_link</a>,
<a name="L1754" href="source/drivers/net/ethernet/smsc/smc91x.c#L1754">1754</a>         .<a href="ident?i=get_eeprom_len">get_eeprom_len</a> = <a href="ident?i=smc_ethtool_geteeprom_len">smc_ethtool_geteeprom_len</a>,
<a name="L1755" href="source/drivers/net/ethernet/smsc/smc91x.c#L1755">1755</a>         .<a href="ident?i=get_eeprom">get_eeprom</a>     = <a href="ident?i=smc_ethtool_geteeprom">smc_ethtool_geteeprom</a>,
<a name="L1756" href="source/drivers/net/ethernet/smsc/smc91x.c#L1756">1756</a>         .<a href="ident?i=set_eeprom">set_eeprom</a>     = <a href="ident?i=smc_ethtool_seteeprom">smc_ethtool_seteeprom</a>,
<a name="L1757" href="source/drivers/net/ethernet/smsc/smc91x.c#L1757">1757</a> };
<a name="L1758" href="source/drivers/net/ethernet/smsc/smc91x.c#L1758">1758</a> 
<a name="L1759" href="source/drivers/net/ethernet/smsc/smc91x.c#L1759">1759</a> static const struct <a href="ident?i=net_device_ops">net_device_ops</a> <a href="ident?i=smc_netdev_ops">smc_netdev_ops</a> = {
<a name="L1760" href="source/drivers/net/ethernet/smsc/smc91x.c#L1760">1760</a>         .ndo_open               = <a href="ident?i=smc_open">smc_open</a>,
<a name="L1761" href="source/drivers/net/ethernet/smsc/smc91x.c#L1761">1761</a>         .ndo_stop               = <a href="ident?i=smc_close">smc_close</a>,
<a name="L1762" href="source/drivers/net/ethernet/smsc/smc91x.c#L1762">1762</a>         .ndo_start_xmit         = <a href="ident?i=smc_hard_start_xmit">smc_hard_start_xmit</a>,
<a name="L1763" href="source/drivers/net/ethernet/smsc/smc91x.c#L1763">1763</a>         .ndo_tx_timeout         = <a href="ident?i=smc_timeout">smc_timeout</a>,
<a name="L1764" href="source/drivers/net/ethernet/smsc/smc91x.c#L1764">1764</a>         .ndo_set_rx_mode        = <a href="ident?i=smc_set_multicast_list">smc_set_multicast_list</a>,
<a name="L1765" href="source/drivers/net/ethernet/smsc/smc91x.c#L1765">1765</a>         .ndo_change_mtu         = <a href="ident?i=eth_change_mtu">eth_change_mtu</a>,
<a name="L1766" href="source/drivers/net/ethernet/smsc/smc91x.c#L1766">1766</a>         .ndo_validate_addr      = <a href="ident?i=eth_validate_addr">eth_validate_addr</a>,
<a name="L1767" href="source/drivers/net/ethernet/smsc/smc91x.c#L1767">1767</a>         .ndo_set_mac_address    = <a href="ident?i=eth_mac_addr">eth_mac_addr</a>,
<a name="L1768" href="source/drivers/net/ethernet/smsc/smc91x.c#L1768">1768</a> #ifdef CONFIG_NET_POLL_CONTROLLER
<a name="L1769" href="source/drivers/net/ethernet/smsc/smc91x.c#L1769">1769</a>         .ndo_poll_controller    = <a href="ident?i=smc_poll_controller">smc_poll_controller</a>,
<a name="L1770" href="source/drivers/net/ethernet/smsc/smc91x.c#L1770">1770</a> #endif
<a name="L1771" href="source/drivers/net/ethernet/smsc/smc91x.c#L1771">1771</a> };
<a name="L1772" href="source/drivers/net/ethernet/smsc/smc91x.c#L1772">1772</a> 
<a name="L1773" href="source/drivers/net/ethernet/smsc/smc91x.c#L1773">1773</a> <b><i>/*</i></b>
<a name="L1774" href="source/drivers/net/ethernet/smsc/smc91x.c#L1774">1774</a> <b><i> * smc_findirq</i></b>
<a name="L1775" href="source/drivers/net/ethernet/smsc/smc91x.c#L1775">1775</a> <b><i> *</i></b>
<a name="L1776" href="source/drivers/net/ethernet/smsc/smc91x.c#L1776">1776</a> <b><i> * This routine has a simple purpose -- make the SMC chip generate an</i></b>
<a name="L1777" href="source/drivers/net/ethernet/smsc/smc91x.c#L1777">1777</a> <b><i> * interrupt, so an auto-detect routine can detect it, and find the IRQ,</i></b>
<a name="L1778" href="source/drivers/net/ethernet/smsc/smc91x.c#L1778">1778</a> <b><i> */</i></b>
<a name="L1779" href="source/drivers/net/ethernet/smsc/smc91x.c#L1779">1779</a> <b><i>/*</i></b>
<a name="L1780" href="source/drivers/net/ethernet/smsc/smc91x.c#L1780">1780</a> <b><i> * does this still work?</i></b>
<a name="L1781" href="source/drivers/net/ethernet/smsc/smc91x.c#L1781">1781</a> <b><i> *</i></b>
<a name="L1782" href="source/drivers/net/ethernet/smsc/smc91x.c#L1782">1782</a> <b><i> * I just deleted auto_irq.c, since it was never built...</i></b>
<a name="L1783" href="source/drivers/net/ethernet/smsc/smc91x.c#L1783">1783</a> <b><i> *   --jgarzik</i></b>
<a name="L1784" href="source/drivers/net/ethernet/smsc/smc91x.c#L1784">1784</a> <b><i> */</i></b>
<a name="L1785" href="source/drivers/net/ethernet/smsc/smc91x.c#L1785">1785</a> static int <a href="ident?i=smc_findirq">smc_findirq</a>(struct <a href="ident?i=smc_local">smc_local</a> *<a href="ident?i=lp">lp</a>)
<a name="L1786" href="source/drivers/net/ethernet/smsc/smc91x.c#L1786">1786</a> {
<a name="L1787" href="source/drivers/net/ethernet/smsc/smc91x.c#L1787">1787</a>         void <a href="ident?i=__iomem">__iomem</a> *<a href="ident?i=ioaddr">ioaddr</a> = <a href="ident?i=lp">lp</a>-&gt;<a href="ident?i=base">base</a>;
<a name="L1788" href="source/drivers/net/ethernet/smsc/smc91x.c#L1788">1788</a>         int <a href="ident?i=timeout">timeout</a> = 20;
<a name="L1789" href="source/drivers/net/ethernet/smsc/smc91x.c#L1789">1789</a>         unsigned long cookie;
<a name="L1790" href="source/drivers/net/ethernet/smsc/smc91x.c#L1790">1790</a> 
<a name="L1791" href="source/drivers/net/ethernet/smsc/smc91x.c#L1791">1791</a>         <a href="ident?i=DBG">DBG</a>(2, <a href="ident?i=lp">lp</a>-&gt;<a href="ident?i=dev">dev</a>, <i>"%s: %s\n"</i>, <a href="ident?i=CARDNAME">CARDNAME</a>, <a href="ident?i=__func__">__func__</a>);
<a name="L1792" href="source/drivers/net/ethernet/smsc/smc91x.c#L1792">1792</a> 
<a name="L1793" href="source/drivers/net/ethernet/smsc/smc91x.c#L1793">1793</a>         cookie = <a href="ident?i=probe_irq_on">probe_irq_on</a>();
<a name="L1794" href="source/drivers/net/ethernet/smsc/smc91x.c#L1794">1794</a> 
<a name="L1795" href="source/drivers/net/ethernet/smsc/smc91x.c#L1795">1795</a>         <b><i>/*</i></b>
<a name="L1796" href="source/drivers/net/ethernet/smsc/smc91x.c#L1796">1796</a> <b><i>         * What I try to do here is trigger an ALLOC_INT. This is done</i></b>
<a name="L1797" href="source/drivers/net/ethernet/smsc/smc91x.c#L1797">1797</a> <b><i>         * by allocating a small chunk of memory, which will give an interrupt</i></b>
<a name="L1798" href="source/drivers/net/ethernet/smsc/smc91x.c#L1798">1798</a> <b><i>         * when done.</i></b>
<a name="L1799" href="source/drivers/net/ethernet/smsc/smc91x.c#L1799">1799</a> <b><i>         */</i></b>
<a name="L1800" href="source/drivers/net/ethernet/smsc/smc91x.c#L1800">1800</a>         <b><i>/* enable ALLOCation interrupts ONLY */</i></b>
<a name="L1801" href="source/drivers/net/ethernet/smsc/smc91x.c#L1801">1801</a>         <a href="ident?i=SMC_SELECT_BANK">SMC_SELECT_BANK</a>(<a href="ident?i=lp">lp</a>, 2);
<a name="L1802" href="source/drivers/net/ethernet/smsc/smc91x.c#L1802">1802</a>         <a href="ident?i=SMC_SET_INT_MASK">SMC_SET_INT_MASK</a>(<a href="ident?i=lp">lp</a>, <a href="ident?i=IM_ALLOC_INT">IM_ALLOC_INT</a>);
<a name="L1803" href="source/drivers/net/ethernet/smsc/smc91x.c#L1803">1803</a> 
<a name="L1804" href="source/drivers/net/ethernet/smsc/smc91x.c#L1804">1804</a>         <b><i>/*</i></b>
<a name="L1805" href="source/drivers/net/ethernet/smsc/smc91x.c#L1805">1805</a> <b><i>         * Allocate 512 bytes of memory.  Note that the chip was just</i></b>
<a name="L1806" href="source/drivers/net/ethernet/smsc/smc91x.c#L1806">1806</a> <b><i>         * reset so all the memory is available</i></b>
<a name="L1807" href="source/drivers/net/ethernet/smsc/smc91x.c#L1807">1807</a> <b><i>         */</i></b>
<a name="L1808" href="source/drivers/net/ethernet/smsc/smc91x.c#L1808">1808</a>         <a href="ident?i=SMC_SET_MMU_CMD">SMC_SET_MMU_CMD</a>(<a href="ident?i=lp">lp</a>, <a href="ident?i=MC_ALLOC">MC_ALLOC</a> | 1);
<a name="L1809" href="source/drivers/net/ethernet/smsc/smc91x.c#L1809">1809</a> 
<a name="L1810" href="source/drivers/net/ethernet/smsc/smc91x.c#L1810">1810</a>         <b><i>/*</i></b>
<a name="L1811" href="source/drivers/net/ethernet/smsc/smc91x.c#L1811">1811</a> <b><i>         * Wait until positive that the interrupt has been generated</i></b>
<a name="L1812" href="source/drivers/net/ethernet/smsc/smc91x.c#L1812">1812</a> <b><i>         */</i></b>
<a name="L1813" href="source/drivers/net/ethernet/smsc/smc91x.c#L1813">1813</a>         do {
<a name="L1814" href="source/drivers/net/ethernet/smsc/smc91x.c#L1814">1814</a>                 int int_status;
<a name="L1815" href="source/drivers/net/ethernet/smsc/smc91x.c#L1815">1815</a>                 <a href="ident?i=udelay">udelay</a>(10);
<a name="L1816" href="source/drivers/net/ethernet/smsc/smc91x.c#L1816">1816</a>                 int_status = <a href="ident?i=SMC_GET_INT">SMC_GET_INT</a>(<a href="ident?i=lp">lp</a>);
<a name="L1817" href="source/drivers/net/ethernet/smsc/smc91x.c#L1817">1817</a>                 if (int_status &amp; <a href="ident?i=IM_ALLOC_INT">IM_ALLOC_INT</a>)
<a name="L1818" href="source/drivers/net/ethernet/smsc/smc91x.c#L1818">1818</a>                         break;          <b><i>/* got the interrupt */</i></b>
<a name="L1819" href="source/drivers/net/ethernet/smsc/smc91x.c#L1819">1819</a>         } while (--<a href="ident?i=timeout">timeout</a>);
<a name="L1820" href="source/drivers/net/ethernet/smsc/smc91x.c#L1820">1820</a> 
<a name="L1821" href="source/drivers/net/ethernet/smsc/smc91x.c#L1821">1821</a>         <b><i>/*</i></b>
<a name="L1822" href="source/drivers/net/ethernet/smsc/smc91x.c#L1822">1822</a> <b><i>         * there is really nothing that I can do here if timeout fails,</i></b>
<a name="L1823" href="source/drivers/net/ethernet/smsc/smc91x.c#L1823">1823</a> <b><i>         * as autoirq_report will return a 0 anyway, which is what I</i></b>
<a name="L1824" href="source/drivers/net/ethernet/smsc/smc91x.c#L1824">1824</a> <b><i>         * want in this case.   Plus, the clean up is needed in both</i></b>
<a name="L1825" href="source/drivers/net/ethernet/smsc/smc91x.c#L1825">1825</a> <b><i>         * cases.</i></b>
<a name="L1826" href="source/drivers/net/ethernet/smsc/smc91x.c#L1826">1826</a> <b><i>         */</i></b>
<a name="L1827" href="source/drivers/net/ethernet/smsc/smc91x.c#L1827">1827</a> 
<a name="L1828" href="source/drivers/net/ethernet/smsc/smc91x.c#L1828">1828</a>         <b><i>/* and disable all interrupts again */</i></b>
<a name="L1829" href="source/drivers/net/ethernet/smsc/smc91x.c#L1829">1829</a>         <a href="ident?i=SMC_SET_INT_MASK">SMC_SET_INT_MASK</a>(<a href="ident?i=lp">lp</a>, 0);
<a name="L1830" href="source/drivers/net/ethernet/smsc/smc91x.c#L1830">1830</a> 
<a name="L1831" href="source/drivers/net/ethernet/smsc/smc91x.c#L1831">1831</a>         <b><i>/* and return what I found */</i></b>
<a name="L1832" href="source/drivers/net/ethernet/smsc/smc91x.c#L1832">1832</a>         return <a href="ident?i=probe_irq_off">probe_irq_off</a>(cookie);
<a name="L1833" href="source/drivers/net/ethernet/smsc/smc91x.c#L1833">1833</a> }
<a name="L1834" href="source/drivers/net/ethernet/smsc/smc91x.c#L1834">1834</a> 
<a name="L1835" href="source/drivers/net/ethernet/smsc/smc91x.c#L1835">1835</a> <b><i>/*</i></b>
<a name="L1836" href="source/drivers/net/ethernet/smsc/smc91x.c#L1836">1836</a> <b><i> * Function: smc_probe(unsigned long ioaddr)</i></b>
<a name="L1837" href="source/drivers/net/ethernet/smsc/smc91x.c#L1837">1837</a> <b><i> *</i></b>
<a name="L1838" href="source/drivers/net/ethernet/smsc/smc91x.c#L1838">1838</a> <b><i> * Purpose:</i></b>
<a name="L1839" href="source/drivers/net/ethernet/smsc/smc91x.c#L1839">1839</a> <b><i> *      Tests to see if a given ioaddr points to an SMC91x chip.</i></b>
<a name="L1840" href="source/drivers/net/ethernet/smsc/smc91x.c#L1840">1840</a> <b><i> *      Returns a 0 on success</i></b>
<a name="L1841" href="source/drivers/net/ethernet/smsc/smc91x.c#L1841">1841</a> <b><i> *</i></b>
<a name="L1842" href="source/drivers/net/ethernet/smsc/smc91x.c#L1842">1842</a> <b><i> * Algorithm:</i></b>
<a name="L1843" href="source/drivers/net/ethernet/smsc/smc91x.c#L1843">1843</a> <b><i> *      (1) see if the high byte of BANK_SELECT is 0x33</i></b>
<a name="L1844" href="source/drivers/net/ethernet/smsc/smc91x.c#L1844">1844</a> <b><i> *      (2) compare the ioaddr with the base register's address</i></b>
<a name="L1845" href="source/drivers/net/ethernet/smsc/smc91x.c#L1845">1845</a> <b><i> *      (3) see if I recognize the chip ID in the appropriate register</i></b>
<a name="L1846" href="source/drivers/net/ethernet/smsc/smc91x.c#L1846">1846</a> <b><i> *</i></b>
<a name="L1847" href="source/drivers/net/ethernet/smsc/smc91x.c#L1847">1847</a> <b><i> * Here I do typical initialization tasks.</i></b>
<a name="L1848" href="source/drivers/net/ethernet/smsc/smc91x.c#L1848">1848</a> <b><i> *</i></b>
<a name="L1849" href="source/drivers/net/ethernet/smsc/smc91x.c#L1849">1849</a> <b><i> * o  Initialize the structure if needed</i></b>
<a name="L1850" href="source/drivers/net/ethernet/smsc/smc91x.c#L1850">1850</a> <b><i> * o  print out my vanity message if not done so already</i></b>
<a name="L1851" href="source/drivers/net/ethernet/smsc/smc91x.c#L1851">1851</a> <b><i> * o  print out what type of hardware is detected</i></b>
<a name="L1852" href="source/drivers/net/ethernet/smsc/smc91x.c#L1852">1852</a> <b><i> * o  print out the ethernet address</i></b>
<a name="L1853" href="source/drivers/net/ethernet/smsc/smc91x.c#L1853">1853</a> <b><i> * o  find the IRQ</i></b>
<a name="L1854" href="source/drivers/net/ethernet/smsc/smc91x.c#L1854">1854</a> <b><i> * o  set up my private data</i></b>
<a name="L1855" href="source/drivers/net/ethernet/smsc/smc91x.c#L1855">1855</a> <b><i> * o  configure the dev structure with my subroutines</i></b>
<a name="L1856" href="source/drivers/net/ethernet/smsc/smc91x.c#L1856">1856</a> <b><i> * o  actually GRAB the irq.</i></b>
<a name="L1857" href="source/drivers/net/ethernet/smsc/smc91x.c#L1857">1857</a> <b><i> * o  GRAB the region</i></b>
<a name="L1858" href="source/drivers/net/ethernet/smsc/smc91x.c#L1858">1858</a> <b><i> */</i></b>
<a name="L1859" href="source/drivers/net/ethernet/smsc/smc91x.c#L1859">1859</a> static int <a href="ident?i=smc_probe">smc_probe</a>(struct <a href="ident?i=net_device">net_device</a> *<a href="ident?i=dev">dev</a>, void <a href="ident?i=__iomem">__iomem</a> *<a href="ident?i=ioaddr">ioaddr</a>,
<a name="L1860" href="source/drivers/net/ethernet/smsc/smc91x.c#L1860">1860</a>                      unsigned long irq_flags)
<a name="L1861" href="source/drivers/net/ethernet/smsc/smc91x.c#L1861">1861</a> {
<a name="L1862" href="source/drivers/net/ethernet/smsc/smc91x.c#L1862">1862</a>         struct <a href="ident?i=smc_local">smc_local</a> *<a href="ident?i=lp">lp</a> = <a href="ident?i=netdev_priv">netdev_priv</a>(<a href="ident?i=dev">dev</a>);
<a name="L1863" href="source/drivers/net/ethernet/smsc/smc91x.c#L1863">1863</a>         int retval;
<a name="L1864" href="source/drivers/net/ethernet/smsc/smc91x.c#L1864">1864</a>         unsigned int <a href="ident?i=val">val</a>, revision_register;
<a name="L1865" href="source/drivers/net/ethernet/smsc/smc91x.c#L1865">1865</a>         const char *<a href="ident?i=version_string">version_string</a>;
<a name="L1866" href="source/drivers/net/ethernet/smsc/smc91x.c#L1866">1866</a> 
<a name="L1867" href="source/drivers/net/ethernet/smsc/smc91x.c#L1867">1867</a>         <a href="ident?i=DBG">DBG</a>(2, <a href="ident?i=dev">dev</a>, <i>"%s: %s\n"</i>, <a href="ident?i=CARDNAME">CARDNAME</a>, <a href="ident?i=__func__">__func__</a>);
<a name="L1868" href="source/drivers/net/ethernet/smsc/smc91x.c#L1868">1868</a> 
<a name="L1869" href="source/drivers/net/ethernet/smsc/smc91x.c#L1869">1869</a>         <b><i>/* First, see if the high byte is 0x33 */</i></b>
<a name="L1870" href="source/drivers/net/ethernet/smsc/smc91x.c#L1870">1870</a>         <a href="ident?i=val">val</a> = <a href="ident?i=SMC_CURRENT_BANK">SMC_CURRENT_BANK</a>(<a href="ident?i=lp">lp</a>);
<a name="L1871" href="source/drivers/net/ethernet/smsc/smc91x.c#L1871">1871</a>         <a href="ident?i=DBG">DBG</a>(2, <a href="ident?i=dev">dev</a>, <i>"%s: bank signature probe returned 0x%04x\n"</i>,
<a name="L1872" href="source/drivers/net/ethernet/smsc/smc91x.c#L1872">1872</a>             <a href="ident?i=CARDNAME">CARDNAME</a>, <a href="ident?i=val">val</a>);
<a name="L1873" href="source/drivers/net/ethernet/smsc/smc91x.c#L1873">1873</a>         if ((<a href="ident?i=val">val</a> &amp; 0xFF00) != 0x3300) {
<a name="L1874" href="source/drivers/net/ethernet/smsc/smc91x.c#L1874">1874</a>                 if ((<a href="ident?i=val">val</a> &amp; 0xFF) == 0x33) {
<a name="L1875" href="source/drivers/net/ethernet/smsc/smc91x.c#L1875">1875</a>                         <a href="ident?i=netdev_warn">netdev_warn</a>(<a href="ident?i=dev">dev</a>,
<a name="L1876" href="source/drivers/net/ethernet/smsc/smc91x.c#L1876">1876</a>                                     <i>"%s: Detected possible byte-swapped interface at IOADDR %p\n"</i>,
<a name="L1877" href="source/drivers/net/ethernet/smsc/smc91x.c#L1877">1877</a>                                     <a href="ident?i=CARDNAME">CARDNAME</a>, <a href="ident?i=ioaddr">ioaddr</a>);
<a name="L1878" href="source/drivers/net/ethernet/smsc/smc91x.c#L1878">1878</a>                 }
<a name="L1879" href="source/drivers/net/ethernet/smsc/smc91x.c#L1879">1879</a>                 retval = -<a href="ident?i=ENODEV">ENODEV</a>;
<a name="L1880" href="source/drivers/net/ethernet/smsc/smc91x.c#L1880">1880</a>                 goto err_out;
<a name="L1881" href="source/drivers/net/ethernet/smsc/smc91x.c#L1881">1881</a>         }
<a name="L1882" href="source/drivers/net/ethernet/smsc/smc91x.c#L1882">1882</a> 
<a name="L1883" href="source/drivers/net/ethernet/smsc/smc91x.c#L1883">1883</a>         <b><i>/*</i></b>
<a name="L1884" href="source/drivers/net/ethernet/smsc/smc91x.c#L1884">1884</a> <b><i>         * The above MIGHT indicate a device, but I need to write to</i></b>
<a name="L1885" href="source/drivers/net/ethernet/smsc/smc91x.c#L1885">1885</a> <b><i>         * further test this.</i></b>
<a name="L1886" href="source/drivers/net/ethernet/smsc/smc91x.c#L1886">1886</a> <b><i>         */</i></b>
<a name="L1887" href="source/drivers/net/ethernet/smsc/smc91x.c#L1887">1887</a>         <a href="ident?i=SMC_SELECT_BANK">SMC_SELECT_BANK</a>(<a href="ident?i=lp">lp</a>, 0);
<a name="L1888" href="source/drivers/net/ethernet/smsc/smc91x.c#L1888">1888</a>         <a href="ident?i=val">val</a> = <a href="ident?i=SMC_CURRENT_BANK">SMC_CURRENT_BANK</a>(<a href="ident?i=lp">lp</a>);
<a name="L1889" href="source/drivers/net/ethernet/smsc/smc91x.c#L1889">1889</a>         if ((<a href="ident?i=val">val</a> &amp; 0xFF00) != 0x3300) {
<a name="L1890" href="source/drivers/net/ethernet/smsc/smc91x.c#L1890">1890</a>                 retval = -<a href="ident?i=ENODEV">ENODEV</a>;
<a name="L1891" href="source/drivers/net/ethernet/smsc/smc91x.c#L1891">1891</a>                 goto err_out;
<a name="L1892" href="source/drivers/net/ethernet/smsc/smc91x.c#L1892">1892</a>         }
<a name="L1893" href="source/drivers/net/ethernet/smsc/smc91x.c#L1893">1893</a> 
<a name="L1894" href="source/drivers/net/ethernet/smsc/smc91x.c#L1894">1894</a>         <b><i>/*</i></b>
<a name="L1895" href="source/drivers/net/ethernet/smsc/smc91x.c#L1895">1895</a> <b><i>         * well, we've already written once, so hopefully another</i></b>
<a name="L1896" href="source/drivers/net/ethernet/smsc/smc91x.c#L1896">1896</a> <b><i>         * time won't hurt.  This time, I need to switch the bank</i></b>
<a name="L1897" href="source/drivers/net/ethernet/smsc/smc91x.c#L1897">1897</a> <b><i>         * register to bank 1, so I can access the base address</i></b>
<a name="L1898" href="source/drivers/net/ethernet/smsc/smc91x.c#L1898">1898</a> <b><i>         * register</i></b>
<a name="L1899" href="source/drivers/net/ethernet/smsc/smc91x.c#L1899">1899</a> <b><i>         */</i></b>
<a name="L1900" href="source/drivers/net/ethernet/smsc/smc91x.c#L1900">1900</a>         <a href="ident?i=SMC_SELECT_BANK">SMC_SELECT_BANK</a>(<a href="ident?i=lp">lp</a>, 1);
<a name="L1901" href="source/drivers/net/ethernet/smsc/smc91x.c#L1901">1901</a>         <a href="ident?i=val">val</a> = <a href="ident?i=SMC_GET_BASE">SMC_GET_BASE</a>(<a href="ident?i=lp">lp</a>);
<a name="L1902" href="source/drivers/net/ethernet/smsc/smc91x.c#L1902">1902</a>         <a href="ident?i=val">val</a> = ((<a href="ident?i=val">val</a> &amp; 0x1F00) &gt;&gt; 3) &lt;&lt; <a href="ident?i=SMC_IO_SHIFT">SMC_IO_SHIFT</a>;
<a name="L1903" href="source/drivers/net/ethernet/smsc/smc91x.c#L1903">1903</a>         if (((unsigned long)<a href="ident?i=ioaddr">ioaddr</a> &amp; (0x3e0 &lt;&lt; <a href="ident?i=SMC_IO_SHIFT">SMC_IO_SHIFT</a>)) != <a href="ident?i=val">val</a>) {
<a name="L1904" href="source/drivers/net/ethernet/smsc/smc91x.c#L1904">1904</a>                 <a href="ident?i=netdev_warn">netdev_warn</a>(<a href="ident?i=dev">dev</a>, <i>"%s: IOADDR %p doesn't match configuration (%x).\n"</i>,
<a name="L1905" href="source/drivers/net/ethernet/smsc/smc91x.c#L1905">1905</a>                             <a href="ident?i=CARDNAME">CARDNAME</a>, <a href="ident?i=ioaddr">ioaddr</a>, <a href="ident?i=val">val</a>);
<a name="L1906" href="source/drivers/net/ethernet/smsc/smc91x.c#L1906">1906</a>         }
<a name="L1907" href="source/drivers/net/ethernet/smsc/smc91x.c#L1907">1907</a> 
<a name="L1908" href="source/drivers/net/ethernet/smsc/smc91x.c#L1908">1908</a>         <b><i>/*</i></b>
<a name="L1909" href="source/drivers/net/ethernet/smsc/smc91x.c#L1909">1909</a> <b><i>         * check if the revision register is something that I</i></b>
<a name="L1910" href="source/drivers/net/ethernet/smsc/smc91x.c#L1910">1910</a> <b><i>         * recognize.  These might need to be added to later,</i></b>
<a name="L1911" href="source/drivers/net/ethernet/smsc/smc91x.c#L1911">1911</a> <b><i>         * as future revisions could be added.</i></b>
<a name="L1912" href="source/drivers/net/ethernet/smsc/smc91x.c#L1912">1912</a> <b><i>         */</i></b>
<a name="L1913" href="source/drivers/net/ethernet/smsc/smc91x.c#L1913">1913</a>         <a href="ident?i=SMC_SELECT_BANK">SMC_SELECT_BANK</a>(<a href="ident?i=lp">lp</a>, 3);
<a name="L1914" href="source/drivers/net/ethernet/smsc/smc91x.c#L1914">1914</a>         revision_register = <a href="ident?i=SMC_GET_REV">SMC_GET_REV</a>(<a href="ident?i=lp">lp</a>);
<a name="L1915" href="source/drivers/net/ethernet/smsc/smc91x.c#L1915">1915</a>         <a href="ident?i=DBG">DBG</a>(2, <a href="ident?i=dev">dev</a>, <i>"%s: revision = 0x%04x\n"</i>, <a href="ident?i=CARDNAME">CARDNAME</a>, revision_register);
<a name="L1916" href="source/drivers/net/ethernet/smsc/smc91x.c#L1916">1916</a>         <a href="ident?i=version_string">version_string</a> = <a href="ident?i=chip_ids">chip_ids</a>[ (revision_register &gt;&gt; 4) &amp; 0xF];
<a name="L1917" href="source/drivers/net/ethernet/smsc/smc91x.c#L1917">1917</a>         if (!<a href="ident?i=version_string">version_string</a> || (revision_register &amp; 0xff00) != 0x3300) {
<a name="L1918" href="source/drivers/net/ethernet/smsc/smc91x.c#L1918">1918</a>                 <b><i>/* I don't recognize this chip, so... */</i></b>
<a name="L1919" href="source/drivers/net/ethernet/smsc/smc91x.c#L1919">1919</a>                 <a href="ident?i=netdev_warn">netdev_warn</a>(<a href="ident?i=dev">dev</a>, <i>"%s: IO %p: Unrecognized revision register 0x%04x, Contact author.\n"</i>,
<a name="L1920" href="source/drivers/net/ethernet/smsc/smc91x.c#L1920">1920</a>                             <a href="ident?i=CARDNAME">CARDNAME</a>, <a href="ident?i=ioaddr">ioaddr</a>, revision_register);
<a name="L1921" href="source/drivers/net/ethernet/smsc/smc91x.c#L1921">1921</a> 
<a name="L1922" href="source/drivers/net/ethernet/smsc/smc91x.c#L1922">1922</a>                 retval = -<a href="ident?i=ENODEV">ENODEV</a>;
<a name="L1923" href="source/drivers/net/ethernet/smsc/smc91x.c#L1923">1923</a>                 goto err_out;
<a name="L1924" href="source/drivers/net/ethernet/smsc/smc91x.c#L1924">1924</a>         }
<a name="L1925" href="source/drivers/net/ethernet/smsc/smc91x.c#L1925">1925</a> 
<a name="L1926" href="source/drivers/net/ethernet/smsc/smc91x.c#L1926">1926</a>         <b><i>/* At this point I'll assume that the chip is an SMC91x. */</i></b>
<a name="L1927" href="source/drivers/net/ethernet/smsc/smc91x.c#L1927">1927</a>         <a href="ident?i=pr_info_once">pr_info_once</a>(<i>"%s\n"</i>, <a href="ident?i=version">version</a>);
<a name="L1928" href="source/drivers/net/ethernet/smsc/smc91x.c#L1928">1928</a> 
<a name="L1929" href="source/drivers/net/ethernet/smsc/smc91x.c#L1929">1929</a>         <b><i>/* fill in some of the fields */</i></b>
<a name="L1930" href="source/drivers/net/ethernet/smsc/smc91x.c#L1930">1930</a>         <a href="ident?i=dev">dev</a>-&gt;<a href="ident?i=base_addr">base_addr</a> = (unsigned long)<a href="ident?i=ioaddr">ioaddr</a>;
<a name="L1931" href="source/drivers/net/ethernet/smsc/smc91x.c#L1931">1931</a>         <a href="ident?i=lp">lp</a>-&gt;<a href="ident?i=base">base</a> = <a href="ident?i=ioaddr">ioaddr</a>;
<a name="L1932" href="source/drivers/net/ethernet/smsc/smc91x.c#L1932">1932</a>         <a href="ident?i=lp">lp</a>-&gt;<a href="ident?i=version">version</a> = revision_register &amp; 0xff;
<a name="L1933" href="source/drivers/net/ethernet/smsc/smc91x.c#L1933">1933</a>         <a href="ident?i=spin_lock_init">spin_lock_init</a>(&amp;<a href="ident?i=lp">lp</a>-&gt;<a href="ident?i=lock">lock</a>);
<a name="L1934" href="source/drivers/net/ethernet/smsc/smc91x.c#L1934">1934</a> 
<a name="L1935" href="source/drivers/net/ethernet/smsc/smc91x.c#L1935">1935</a>         <b><i>/* Get the MAC address */</i></b>
<a name="L1936" href="source/drivers/net/ethernet/smsc/smc91x.c#L1936">1936</a>         <a href="ident?i=SMC_SELECT_BANK">SMC_SELECT_BANK</a>(<a href="ident?i=lp">lp</a>, 1);
<a name="L1937" href="source/drivers/net/ethernet/smsc/smc91x.c#L1937">1937</a>         <a href="ident?i=SMC_GET_MAC_ADDR">SMC_GET_MAC_ADDR</a>(<a href="ident?i=lp">lp</a>, <a href="ident?i=dev">dev</a>-&gt;dev_addr);
<a name="L1938" href="source/drivers/net/ethernet/smsc/smc91x.c#L1938">1938</a> 
<a name="L1939" href="source/drivers/net/ethernet/smsc/smc91x.c#L1939">1939</a>         <b><i>/* now, reset the chip, and put it into a known state */</i></b>
<a name="L1940" href="source/drivers/net/ethernet/smsc/smc91x.c#L1940">1940</a>         <a href="ident?i=smc_reset">smc_reset</a>(<a href="ident?i=dev">dev</a>);
<a name="L1941" href="source/drivers/net/ethernet/smsc/smc91x.c#L1941">1941</a> 
<a name="L1942" href="source/drivers/net/ethernet/smsc/smc91x.c#L1942">1942</a>         <b><i>/*</i></b>
<a name="L1943" href="source/drivers/net/ethernet/smsc/smc91x.c#L1943">1943</a> <b><i>         * If dev-&gt;irq is 0, then the device has to be banged on to see</i></b>
<a name="L1944" href="source/drivers/net/ethernet/smsc/smc91x.c#L1944">1944</a> <b><i>         * what the IRQ is.</i></b>
<a name="L1945" href="source/drivers/net/ethernet/smsc/smc91x.c#L1945">1945</a> <b><i>         *</i></b>
<a name="L1946" href="source/drivers/net/ethernet/smsc/smc91x.c#L1946">1946</a> <b><i>         * This banging doesn't always detect the IRQ, for unknown reasons.</i></b>
<a name="L1947" href="source/drivers/net/ethernet/smsc/smc91x.c#L1947">1947</a> <b><i>         * a workaround is to reset the chip and try again.</i></b>
<a name="L1948" href="source/drivers/net/ethernet/smsc/smc91x.c#L1948">1948</a> <b><i>         *</i></b>
<a name="L1949" href="source/drivers/net/ethernet/smsc/smc91x.c#L1949">1949</a> <b><i>         * Interestingly, the DOS packet driver *SETS* the IRQ on the card to</i></b>
<a name="L1950" href="source/drivers/net/ethernet/smsc/smc91x.c#L1950">1950</a> <b><i>         * be what is requested on the command line.   I don't do that, mostly</i></b>
<a name="L1951" href="source/drivers/net/ethernet/smsc/smc91x.c#L1951">1951</a> <b><i>         * because the card that I have uses a non-standard method of accessing</i></b>
<a name="L1952" href="source/drivers/net/ethernet/smsc/smc91x.c#L1952">1952</a> <b><i>         * the IRQs, and because this _should_ work in most configurations.</i></b>
<a name="L1953" href="source/drivers/net/ethernet/smsc/smc91x.c#L1953">1953</a> <b><i>         *</i></b>
<a name="L1954" href="source/drivers/net/ethernet/smsc/smc91x.c#L1954">1954</a> <b><i>         * Specifying an IRQ is done with the assumption that the user knows</i></b>
<a name="L1955" href="source/drivers/net/ethernet/smsc/smc91x.c#L1955">1955</a> <b><i>         * what (s)he is doing.  No checking is done!!!!</i></b>
<a name="L1956" href="source/drivers/net/ethernet/smsc/smc91x.c#L1956">1956</a> <b><i>         */</i></b>
<a name="L1957" href="source/drivers/net/ethernet/smsc/smc91x.c#L1957">1957</a>         if (<a href="ident?i=dev">dev</a>-&gt;<a href="ident?i=irq">irq</a> &lt; 1) {
<a name="L1958" href="source/drivers/net/ethernet/smsc/smc91x.c#L1958">1958</a>                 int trials;
<a name="L1959" href="source/drivers/net/ethernet/smsc/smc91x.c#L1959">1959</a> 
<a name="L1960" href="source/drivers/net/ethernet/smsc/smc91x.c#L1960">1960</a>                 trials = 3;
<a name="L1961" href="source/drivers/net/ethernet/smsc/smc91x.c#L1961">1961</a>                 while (trials--) {
<a name="L1962" href="source/drivers/net/ethernet/smsc/smc91x.c#L1962">1962</a>                         <a href="ident?i=dev">dev</a>-&gt;<a href="ident?i=irq">irq</a> = <a href="ident?i=smc_findirq">smc_findirq</a>(<a href="ident?i=lp">lp</a>);
<a name="L1963" href="source/drivers/net/ethernet/smsc/smc91x.c#L1963">1963</a>                         if (<a href="ident?i=dev">dev</a>-&gt;<a href="ident?i=irq">irq</a>)
<a name="L1964" href="source/drivers/net/ethernet/smsc/smc91x.c#L1964">1964</a>                                 break;
<a name="L1965" href="source/drivers/net/ethernet/smsc/smc91x.c#L1965">1965</a>                         <b><i>/* kick the card and try again */</i></b>
<a name="L1966" href="source/drivers/net/ethernet/smsc/smc91x.c#L1966">1966</a>                         <a href="ident?i=smc_reset">smc_reset</a>(<a href="ident?i=dev">dev</a>);
<a name="L1967" href="source/drivers/net/ethernet/smsc/smc91x.c#L1967">1967</a>                 }
<a name="L1968" href="source/drivers/net/ethernet/smsc/smc91x.c#L1968">1968</a>         }
<a name="L1969" href="source/drivers/net/ethernet/smsc/smc91x.c#L1969">1969</a>         if (<a href="ident?i=dev">dev</a>-&gt;<a href="ident?i=irq">irq</a> == 0) {
<a name="L1970" href="source/drivers/net/ethernet/smsc/smc91x.c#L1970">1970</a>                 <a href="ident?i=netdev_warn">netdev_warn</a>(<a href="ident?i=dev">dev</a>, <i>"Couldn't autodetect your IRQ. Use irq=xx.\n"</i>);
<a name="L1971" href="source/drivers/net/ethernet/smsc/smc91x.c#L1971">1971</a>                 retval = -<a href="ident?i=ENODEV">ENODEV</a>;
<a name="L1972" href="source/drivers/net/ethernet/smsc/smc91x.c#L1972">1972</a>                 goto err_out;
<a name="L1973" href="source/drivers/net/ethernet/smsc/smc91x.c#L1973">1973</a>         }
<a name="L1974" href="source/drivers/net/ethernet/smsc/smc91x.c#L1974">1974</a>         <a href="ident?i=dev">dev</a>-&gt;<a href="ident?i=irq">irq</a> = <a href="ident?i=irq_canonicalize">irq_canonicalize</a>(<a href="ident?i=dev">dev</a>-&gt;<a href="ident?i=irq">irq</a>);
<a name="L1975" href="source/drivers/net/ethernet/smsc/smc91x.c#L1975">1975</a> 
<a name="L1976" href="source/drivers/net/ethernet/smsc/smc91x.c#L1976">1976</a>         <a href="ident?i=dev">dev</a>-&gt;watchdog_timeo = <a href="ident?i=msecs_to_jiffies">msecs_to_jiffies</a>(<a href="ident?i=watchdog">watchdog</a>);
<a name="L1977" href="source/drivers/net/ethernet/smsc/smc91x.c#L1977">1977</a>         <a href="ident?i=dev">dev</a>-&gt;<a href="ident?i=netdev_ops">netdev_ops</a> = &amp;<a href="ident?i=smc_netdev_ops">smc_netdev_ops</a>;
<a name="L1978" href="source/drivers/net/ethernet/smsc/smc91x.c#L1978">1978</a>         <a href="ident?i=dev">dev</a>-&gt;<a href="ident?i=ethtool_ops">ethtool_ops</a> = &amp;<a href="ident?i=smc_ethtool_ops">smc_ethtool_ops</a>;
<a name="L1979" href="source/drivers/net/ethernet/smsc/smc91x.c#L1979">1979</a> 
<a name="L1980" href="source/drivers/net/ethernet/smsc/smc91x.c#L1980">1980</a>         <a href="ident?i=tasklet_init">tasklet_init</a>(&amp;<a href="ident?i=lp">lp</a>-&gt;tx_task, <a href="ident?i=smc_hardware_send_pkt">smc_hardware_send_pkt</a>, (unsigned long)<a href="ident?i=dev">dev</a>);
<a name="L1981" href="source/drivers/net/ethernet/smsc/smc91x.c#L1981">1981</a>         <a href="ident?i=INIT_WORK">INIT_WORK</a>(&amp;<a href="ident?i=lp">lp</a>-&gt;phy_configure, <a href="ident?i=smc_phy_configure">smc_phy_configure</a>);
<a name="L1982" href="source/drivers/net/ethernet/smsc/smc91x.c#L1982">1982</a>         <a href="ident?i=lp">lp</a>-&gt;<a href="ident?i=dev">dev</a> = <a href="ident?i=dev">dev</a>;
<a name="L1983" href="source/drivers/net/ethernet/smsc/smc91x.c#L1983">1983</a>         <a href="ident?i=lp">lp</a>-&gt;mii.phy_id_mask = 0x1f;
<a name="L1984" href="source/drivers/net/ethernet/smsc/smc91x.c#L1984">1984</a>         <a href="ident?i=lp">lp</a>-&gt;mii.reg_num_mask = 0x1f;
<a name="L1985" href="source/drivers/net/ethernet/smsc/smc91x.c#L1985">1985</a>         <a href="ident?i=lp">lp</a>-&gt;mii.force_media = 0;
<a name="L1986" href="source/drivers/net/ethernet/smsc/smc91x.c#L1986">1986</a>         <a href="ident?i=lp">lp</a>-&gt;mii.<a href="ident?i=full_duplex">full_duplex</a> = 0;
<a name="L1987" href="source/drivers/net/ethernet/smsc/smc91x.c#L1987">1987</a>         <a href="ident?i=lp">lp</a>-&gt;mii.<a href="ident?i=dev">dev</a> = <a href="ident?i=dev">dev</a>;
<a name="L1988" href="source/drivers/net/ethernet/smsc/smc91x.c#L1988">1988</a>         <a href="ident?i=lp">lp</a>-&gt;mii.<a href="ident?i=mdio_read">mdio_read</a> = <a href="ident?i=smc_phy_read">smc_phy_read</a>;
<a name="L1989" href="source/drivers/net/ethernet/smsc/smc91x.c#L1989">1989</a>         <a href="ident?i=lp">lp</a>-&gt;mii.<a href="ident?i=mdio_write">mdio_write</a> = <a href="ident?i=smc_phy_write">smc_phy_write</a>;
<a name="L1990" href="source/drivers/net/ethernet/smsc/smc91x.c#L1990">1990</a> 
<a name="L1991" href="source/drivers/net/ethernet/smsc/smc91x.c#L1991">1991</a>         <b><i>/*</i></b>
<a name="L1992" href="source/drivers/net/ethernet/smsc/smc91x.c#L1992">1992</a> <b><i>         * Locate the phy, if any.</i></b>
<a name="L1993" href="source/drivers/net/ethernet/smsc/smc91x.c#L1993">1993</a> <b><i>         */</i></b>
<a name="L1994" href="source/drivers/net/ethernet/smsc/smc91x.c#L1994">1994</a>         if (<a href="ident?i=lp">lp</a>-&gt;<a href="ident?i=version">version</a> &gt;= (<a href="ident?i=CHIP_91100">CHIP_91100</a> &lt;&lt; 4))
<a name="L1995" href="source/drivers/net/ethernet/smsc/smc91x.c#L1995">1995</a>                 <a href="ident?i=smc_phy_detect">smc_phy_detect</a>(<a href="ident?i=dev">dev</a>);
<a name="L1996" href="source/drivers/net/ethernet/smsc/smc91x.c#L1996">1996</a> 
<a name="L1997" href="source/drivers/net/ethernet/smsc/smc91x.c#L1997">1997</a>         <b><i>/* then shut everything down to save power */</i></b>
<a name="L1998" href="source/drivers/net/ethernet/smsc/smc91x.c#L1998">1998</a>         <a href="ident?i=smc_shutdown">smc_shutdown</a>(<a href="ident?i=dev">dev</a>);
<a name="L1999" href="source/drivers/net/ethernet/smsc/smc91x.c#L1999">1999</a>         <a href="ident?i=smc_phy_powerdown">smc_phy_powerdown</a>(<a href="ident?i=dev">dev</a>);
<a name="L2000" href="source/drivers/net/ethernet/smsc/smc91x.c#L2000">2000</a> 
<a name="L2001" href="source/drivers/net/ethernet/smsc/smc91x.c#L2001">2001</a>         <b><i>/* Set default parameters */</i></b>
<a name="L2002" href="source/drivers/net/ethernet/smsc/smc91x.c#L2002">2002</a>         <a href="ident?i=lp">lp</a>-&gt;<a href="ident?i=msg_enable">msg_enable</a> = NETIF_MSG_LINK;
<a name="L2003" href="source/drivers/net/ethernet/smsc/smc91x.c#L2003">2003</a>         <a href="ident?i=lp">lp</a>-&gt;ctl_rfduplx = 0;
<a name="L2004" href="source/drivers/net/ethernet/smsc/smc91x.c#L2004">2004</a>         <a href="ident?i=lp">lp</a>-&gt;ctl_rspeed = 10;
<a name="L2005" href="source/drivers/net/ethernet/smsc/smc91x.c#L2005">2005</a> 
<a name="L2006" href="source/drivers/net/ethernet/smsc/smc91x.c#L2006">2006</a>         if (<a href="ident?i=lp">lp</a>-&gt;<a href="ident?i=version">version</a> &gt;= (<a href="ident?i=CHIP_91100">CHIP_91100</a> &lt;&lt; 4)) {
<a name="L2007" href="source/drivers/net/ethernet/smsc/smc91x.c#L2007">2007</a>                 <a href="ident?i=lp">lp</a>-&gt;ctl_rfduplx = 1;
<a name="L2008" href="source/drivers/net/ethernet/smsc/smc91x.c#L2008">2008</a>                 <a href="ident?i=lp">lp</a>-&gt;ctl_rspeed = 100;
<a name="L2009" href="source/drivers/net/ethernet/smsc/smc91x.c#L2009">2009</a>         }
<a name="L2010" href="source/drivers/net/ethernet/smsc/smc91x.c#L2010">2010</a> 
<a name="L2011" href="source/drivers/net/ethernet/smsc/smc91x.c#L2011">2011</a>         <b><i>/* Grab the IRQ */</i></b>
<a name="L2012" href="source/drivers/net/ethernet/smsc/smc91x.c#L2012">2012</a>         retval = <a href="ident?i=request_irq">request_irq</a>(<a href="ident?i=dev">dev</a>-&gt;<a href="ident?i=irq">irq</a>, <a href="ident?i=smc_interrupt">smc_interrupt</a>, irq_flags, <a href="ident?i=dev">dev</a>-&gt;<a href="ident?i=name">name</a>, <a href="ident?i=dev">dev</a>);
<a name="L2013" href="source/drivers/net/ethernet/smsc/smc91x.c#L2013">2013</a>         if (retval)
<a name="L2014" href="source/drivers/net/ethernet/smsc/smc91x.c#L2014">2014</a>                 goto err_out;
<a name="L2015" href="source/drivers/net/ethernet/smsc/smc91x.c#L2015">2015</a> 
<a name="L2016" href="source/drivers/net/ethernet/smsc/smc91x.c#L2016">2016</a> #ifdef CONFIG_ARCH_PXA
<a name="L2017" href="source/drivers/net/ethernet/smsc/smc91x.c#L2017">2017</a> #  ifdef <a href="ident?i=SMC_USE_PXA_DMA">SMC_USE_PXA_DMA</a>
<a name="L2018" href="source/drivers/net/ethernet/smsc/smc91x.c#L2018">2018</a>         <a href="ident?i=lp">lp</a>-&gt;<a href="ident?i=cfg">cfg</a>.<a href="ident?i=flags">flags</a> |= <a href="ident?i=SMC91X_USE_DMA">SMC91X_USE_DMA</a>;
<a name="L2019" href="source/drivers/net/ethernet/smsc/smc91x.c#L2019">2019</a> #  <a href="ident?i=endif">endif</a>
<a name="L2020" href="source/drivers/net/ethernet/smsc/smc91x.c#L2020">2020</a>         if (<a href="ident?i=lp">lp</a>-&gt;<a href="ident?i=cfg">cfg</a>.<a href="ident?i=flags">flags</a> &amp; <a href="ident?i=SMC91X_USE_DMA">SMC91X_USE_DMA</a>) {
<a name="L2021" href="source/drivers/net/ethernet/smsc/smc91x.c#L2021">2021</a>                 <a href="ident?i=dma_cap_mask_t">dma_cap_mask_t</a> <a href="ident?i=mask">mask</a>;
<a name="L2022" href="source/drivers/net/ethernet/smsc/smc91x.c#L2022">2022</a>                 struct <a href="ident?i=pxad_param">pxad_param</a> <a href="ident?i=param">param</a>;
<a name="L2023" href="source/drivers/net/ethernet/smsc/smc91x.c#L2023">2023</a> 
<a name="L2024" href="source/drivers/net/ethernet/smsc/smc91x.c#L2024">2024</a>                 <a href="ident?i=dma_cap_zero">dma_cap_zero</a>(<a href="ident?i=mask">mask</a>);
<a name="L2025" href="source/drivers/net/ethernet/smsc/smc91x.c#L2025">2025</a>                 <a href="ident?i=dma_cap_set">dma_cap_set</a>(DMA_SLAVE, <a href="ident?i=mask">mask</a>);
<a name="L2026" href="source/drivers/net/ethernet/smsc/smc91x.c#L2026">2026</a>                 <a href="ident?i=param">param</a>.prio = PXAD_PRIO_LOWEST;
<a name="L2027" href="source/drivers/net/ethernet/smsc/smc91x.c#L2027">2027</a>                 <a href="ident?i=param">param</a>.drcmr = -1UL;
<a name="L2028" href="source/drivers/net/ethernet/smsc/smc91x.c#L2028">2028</a> 
<a name="L2029" href="source/drivers/net/ethernet/smsc/smc91x.c#L2029">2029</a>                 <a href="ident?i=lp">lp</a>-&gt;<a href="ident?i=dma_chan">dma_chan</a> =
<a name="L2030" href="source/drivers/net/ethernet/smsc/smc91x.c#L2030">2030</a>                         <a href="ident?i=dma_request_slave_channel_compat">dma_request_slave_channel_compat</a>(<a href="ident?i=mask">mask</a>, <a href="ident?i=pxad_filter_fn">pxad_filter_fn</a>,
<a name="L2031" href="source/drivers/net/ethernet/smsc/smc91x.c#L2031">2031</a>                                                          &amp;<a href="ident?i=param">param</a>, &amp;<a href="ident?i=dev">dev</a>-&gt;<a href="ident?i=dev">dev</a>,
<a name="L2032" href="source/drivers/net/ethernet/smsc/smc91x.c#L2032">2032</a>                                                          <i>"data"</i>);
<a name="L2033" href="source/drivers/net/ethernet/smsc/smc91x.c#L2033">2033</a>         }
<a name="L2034" href="source/drivers/net/ethernet/smsc/smc91x.c#L2034">2034</a> #endif
<a name="L2035" href="source/drivers/net/ethernet/smsc/smc91x.c#L2035">2035</a> 
<a name="L2036" href="source/drivers/net/ethernet/smsc/smc91x.c#L2036">2036</a>         retval = <a href="ident?i=register_netdev">register_netdev</a>(<a href="ident?i=dev">dev</a>);
<a name="L2037" href="source/drivers/net/ethernet/smsc/smc91x.c#L2037">2037</a>         if (retval == 0) {
<a name="L2038" href="source/drivers/net/ethernet/smsc/smc91x.c#L2038">2038</a>                 <b><i>/* now, print out the card info, in a short format.. */</i></b>
<a name="L2039" href="source/drivers/net/ethernet/smsc/smc91x.c#L2039">2039</a>                 <a href="ident?i=netdev_info">netdev_info</a>(<a href="ident?i=dev">dev</a>, <i>"%s (rev %d) at %p IRQ %d"</i>,
<a name="L2040" href="source/drivers/net/ethernet/smsc/smc91x.c#L2040">2040</a>                             <a href="ident?i=version_string">version_string</a>, revision_register &amp; 0x0f,
<a name="L2041" href="source/drivers/net/ethernet/smsc/smc91x.c#L2041">2041</a>                             <a href="ident?i=lp">lp</a>-&gt;<a href="ident?i=base">base</a>, <a href="ident?i=dev">dev</a>-&gt;<a href="ident?i=irq">irq</a>);
<a name="L2042" href="source/drivers/net/ethernet/smsc/smc91x.c#L2042">2042</a> 
<a name="L2043" href="source/drivers/net/ethernet/smsc/smc91x.c#L2043">2043</a>                 if (<a href="ident?i=lp">lp</a>-&gt;<a href="ident?i=dma_chan">dma_chan</a>)
<a name="L2044" href="source/drivers/net/ethernet/smsc/smc91x.c#L2044">2044</a>                         <a href="ident?i=pr_cont">pr_cont</a>(<i>" DMA %p"</i>, <a href="ident?i=lp">lp</a>-&gt;<a href="ident?i=dma_chan">dma_chan</a>);
<a name="L2045" href="source/drivers/net/ethernet/smsc/smc91x.c#L2045">2045</a> 
<a name="L2046" href="source/drivers/net/ethernet/smsc/smc91x.c#L2046">2046</a>                 <a href="ident?i=pr_cont">pr_cont</a>(<i>"%s%s\n"</i>,
<a name="L2047" href="source/drivers/net/ethernet/smsc/smc91x.c#L2047">2047</a>                         <a href="ident?i=lp">lp</a>-&gt;<a href="ident?i=cfg">cfg</a>.<a href="ident?i=flags">flags</a> &amp; <a href="ident?i=SMC91X_NOWAIT">SMC91X_NOWAIT</a> ? <i>" [nowait]"</i> : <i>""</i>,
<a name="L2048" href="source/drivers/net/ethernet/smsc/smc91x.c#L2048">2048</a>                         <a href="ident?i=THROTTLE_TX_PKTS">THROTTLE_TX_PKTS</a> ? <i>" [throttle_tx]"</i> : <i>""</i>);
<a name="L2049" href="source/drivers/net/ethernet/smsc/smc91x.c#L2049">2049</a> 
<a name="L2050" href="source/drivers/net/ethernet/smsc/smc91x.c#L2050">2050</a>                 if (!<a href="ident?i=is_valid_ether_addr">is_valid_ether_addr</a>(<a href="ident?i=dev">dev</a>-&gt;dev_addr)) {
<a name="L2051" href="source/drivers/net/ethernet/smsc/smc91x.c#L2051">2051</a>                         <a href="ident?i=netdev_warn">netdev_warn</a>(<a href="ident?i=dev">dev</a>, <i>"Invalid ethernet MAC address. Please set using ifconfig\n"</i>);
<a name="L2052" href="source/drivers/net/ethernet/smsc/smc91x.c#L2052">2052</a>                 } else {
<a name="L2053" href="source/drivers/net/ethernet/smsc/smc91x.c#L2053">2053</a>                         <b><i>/* Print the Ethernet address */</i></b>
<a name="L2054" href="source/drivers/net/ethernet/smsc/smc91x.c#L2054">2054</a>                         <a href="ident?i=netdev_info">netdev_info</a>(<a href="ident?i=dev">dev</a>, <i>"Ethernet addr: %pM\n"</i>,
<a name="L2055" href="source/drivers/net/ethernet/smsc/smc91x.c#L2055">2055</a>                                     <a href="ident?i=dev">dev</a>-&gt;dev_addr);
<a name="L2056" href="source/drivers/net/ethernet/smsc/smc91x.c#L2056">2056</a>                 }
<a name="L2057" href="source/drivers/net/ethernet/smsc/smc91x.c#L2057">2057</a> 
<a name="L2058" href="source/drivers/net/ethernet/smsc/smc91x.c#L2058">2058</a>                 if (<a href="ident?i=lp">lp</a>-&gt;phy_type == 0) {
<a name="L2059" href="source/drivers/net/ethernet/smsc/smc91x.c#L2059">2059</a>                         <a href="ident?i=PRINTK">PRINTK</a>(<a href="ident?i=dev">dev</a>, <i>"No PHY found\n"</i>);
<a name="L2060" href="source/drivers/net/ethernet/smsc/smc91x.c#L2060">2060</a>                 } else if ((<a href="ident?i=lp">lp</a>-&gt;phy_type &amp; 0xfffffff0) == 0x0016f840) {
<a name="L2061" href="source/drivers/net/ethernet/smsc/smc91x.c#L2061">2061</a>                         <a href="ident?i=PRINTK">PRINTK</a>(<a href="ident?i=dev">dev</a>, <i>"PHY LAN83C183 (LAN91C111 Internal)\n"</i>);
<a name="L2062" href="source/drivers/net/ethernet/smsc/smc91x.c#L2062">2062</a>                 } else if ((<a href="ident?i=lp">lp</a>-&gt;phy_type &amp; 0xfffffff0) == 0x02821c50) {
<a name="L2063" href="source/drivers/net/ethernet/smsc/smc91x.c#L2063">2063</a>                         <a href="ident?i=PRINTK">PRINTK</a>(<a href="ident?i=dev">dev</a>, <i>"PHY LAN83C180\n"</i>);
<a name="L2064" href="source/drivers/net/ethernet/smsc/smc91x.c#L2064">2064</a>                 }
<a name="L2065" href="source/drivers/net/ethernet/smsc/smc91x.c#L2065">2065</a>         }
<a name="L2066" href="source/drivers/net/ethernet/smsc/smc91x.c#L2066">2066</a> 
<a name="L2067" href="source/drivers/net/ethernet/smsc/smc91x.c#L2067">2067</a> err_out:
<a name="L2068" href="source/drivers/net/ethernet/smsc/smc91x.c#L2068">2068</a> #ifdef CONFIG_ARCH_PXA
<a name="L2069" href="source/drivers/net/ethernet/smsc/smc91x.c#L2069">2069</a>         if (retval &amp;&amp; <a href="ident?i=lp">lp</a>-&gt;<a href="ident?i=dma_chan">dma_chan</a>)
<a name="L2070" href="source/drivers/net/ethernet/smsc/smc91x.c#L2070">2070</a>                 <a href="ident?i=dma_release_channel">dma_release_channel</a>(<a href="ident?i=lp">lp</a>-&gt;<a href="ident?i=dma_chan">dma_chan</a>);
<a name="L2071" href="source/drivers/net/ethernet/smsc/smc91x.c#L2071">2071</a> #endif
<a name="L2072" href="source/drivers/net/ethernet/smsc/smc91x.c#L2072">2072</a>         return retval;
<a name="L2073" href="source/drivers/net/ethernet/smsc/smc91x.c#L2073">2073</a> }
<a name="L2074" href="source/drivers/net/ethernet/smsc/smc91x.c#L2074">2074</a> 
<a name="L2075" href="source/drivers/net/ethernet/smsc/smc91x.c#L2075">2075</a> static int <a href="ident?i=smc_enable_device">smc_enable_device</a>(struct <a href="ident?i=platform_device">platform_device</a> *<a href="ident?i=pdev">pdev</a>)
<a name="L2076" href="source/drivers/net/ethernet/smsc/smc91x.c#L2076">2076</a> {
<a name="L2077" href="source/drivers/net/ethernet/smsc/smc91x.c#L2077">2077</a>         struct <a href="ident?i=net_device">net_device</a> *ndev = <a href="ident?i=platform_get_drvdata">platform_get_drvdata</a>(<a href="ident?i=pdev">pdev</a>);
<a name="L2078" href="source/drivers/net/ethernet/smsc/smc91x.c#L2078">2078</a>         struct <a href="ident?i=smc_local">smc_local</a> *<a href="ident?i=lp">lp</a> = <a href="ident?i=netdev_priv">netdev_priv</a>(ndev);
<a name="L2079" href="source/drivers/net/ethernet/smsc/smc91x.c#L2079">2079</a>         unsigned long <a href="ident?i=flags">flags</a>;
<a name="L2080" href="source/drivers/net/ethernet/smsc/smc91x.c#L2080">2080</a>         unsigned char ecor, ecsr;
<a name="L2081" href="source/drivers/net/ethernet/smsc/smc91x.c#L2081">2081</a>         void <a href="ident?i=__iomem">__iomem</a> *<a href="ident?i=addr">addr</a>;
<a name="L2082" href="source/drivers/net/ethernet/smsc/smc91x.c#L2082">2082</a>         struct <a href="ident?i=resource">resource</a> * <a href="ident?i=res">res</a>;
<a name="L2083" href="source/drivers/net/ethernet/smsc/smc91x.c#L2083">2083</a> 
<a name="L2084" href="source/drivers/net/ethernet/smsc/smc91x.c#L2084">2084</a>         <a href="ident?i=res">res</a> = <a href="ident?i=platform_get_resource_byname">platform_get_resource_byname</a>(<a href="ident?i=pdev">pdev</a>, <a href="ident?i=IORESOURCE_MEM">IORESOURCE_MEM</a>, <i>"smc91x-attrib"</i>);
<a name="L2085" href="source/drivers/net/ethernet/smsc/smc91x.c#L2085">2085</a>         if (!<a href="ident?i=res">res</a>)
<a name="L2086" href="source/drivers/net/ethernet/smsc/smc91x.c#L2086">2086</a>                 return 0;
<a name="L2087" href="source/drivers/net/ethernet/smsc/smc91x.c#L2087">2087</a> 
<a name="L2088" href="source/drivers/net/ethernet/smsc/smc91x.c#L2088">2088</a>         <b><i>/*</i></b>
<a name="L2089" href="source/drivers/net/ethernet/smsc/smc91x.c#L2089">2089</a> <b><i>         * Map the attribute space.  This is overkill, but clean.</i></b>
<a name="L2090" href="source/drivers/net/ethernet/smsc/smc91x.c#L2090">2090</a> <b><i>         */</i></b>
<a name="L2091" href="source/drivers/net/ethernet/smsc/smc91x.c#L2091">2091</a>         <a href="ident?i=addr">addr</a> = <a href="ident?i=ioremap">ioremap</a>(<a href="ident?i=res">res</a>-&gt;<a href="ident?i=start">start</a>, <a href="ident?i=ATTRIB_SIZE">ATTRIB_SIZE</a>);
<a name="L2092" href="source/drivers/net/ethernet/smsc/smc91x.c#L2092">2092</a>         if (!<a href="ident?i=addr">addr</a>)
<a name="L2093" href="source/drivers/net/ethernet/smsc/smc91x.c#L2093">2093</a>                 return -<a href="ident?i=ENOMEM">ENOMEM</a>;
<a name="L2094" href="source/drivers/net/ethernet/smsc/smc91x.c#L2094">2094</a> 
<a name="L2095" href="source/drivers/net/ethernet/smsc/smc91x.c#L2095">2095</a>         <b><i>/*</i></b>
<a name="L2096" href="source/drivers/net/ethernet/smsc/smc91x.c#L2096">2096</a> <b><i>         * Reset the device.  We must disable IRQs around this</i></b>
<a name="L2097" href="source/drivers/net/ethernet/smsc/smc91x.c#L2097">2097</a> <b><i>         * since a reset causes the IRQ line become active.</i></b>
<a name="L2098" href="source/drivers/net/ethernet/smsc/smc91x.c#L2098">2098</a> <b><i>         */</i></b>
<a name="L2099" href="source/drivers/net/ethernet/smsc/smc91x.c#L2099">2099</a>         <a href="ident?i=local_irq_save">local_irq_save</a>(<a href="ident?i=flags">flags</a>);
<a name="L2100" href="source/drivers/net/ethernet/smsc/smc91x.c#L2100">2100</a>         ecor = <a href="ident?i=readb">readb</a>(<a href="ident?i=addr">addr</a> + (<a href="ident?i=ECOR">ECOR</a> &lt;&lt; <a href="ident?i=SMC_IO_SHIFT">SMC_IO_SHIFT</a>)) &amp; ~ECOR_RESET;
<a name="L2101" href="source/drivers/net/ethernet/smsc/smc91x.c#L2101">2101</a>         <a href="ident?i=writeb">writeb</a>(ecor | <a href="ident?i=ECOR_RESET">ECOR_RESET</a>, <a href="ident?i=addr">addr</a> + (<a href="ident?i=ECOR">ECOR</a> &lt;&lt; <a href="ident?i=SMC_IO_SHIFT">SMC_IO_SHIFT</a>));
<a name="L2102" href="source/drivers/net/ethernet/smsc/smc91x.c#L2102">2102</a>         <a href="ident?i=readb">readb</a>(<a href="ident?i=addr">addr</a> + (<a href="ident?i=ECOR">ECOR</a> &lt;&lt; <a href="ident?i=SMC_IO_SHIFT">SMC_IO_SHIFT</a>));
<a name="L2103" href="source/drivers/net/ethernet/smsc/smc91x.c#L2103">2103</a> 
<a name="L2104" href="source/drivers/net/ethernet/smsc/smc91x.c#L2104">2104</a>         <b><i>/*</i></b>
<a name="L2105" href="source/drivers/net/ethernet/smsc/smc91x.c#L2105">2105</a> <b><i>         * Wait 100us for the chip to reset.</i></b>
<a name="L2106" href="source/drivers/net/ethernet/smsc/smc91x.c#L2106">2106</a> <b><i>         */</i></b>
<a name="L2107" href="source/drivers/net/ethernet/smsc/smc91x.c#L2107">2107</a>         <a href="ident?i=udelay">udelay</a>(100);
<a name="L2108" href="source/drivers/net/ethernet/smsc/smc91x.c#L2108">2108</a> 
<a name="L2109" href="source/drivers/net/ethernet/smsc/smc91x.c#L2109">2109</a>         <b><i>/*</i></b>
<a name="L2110" href="source/drivers/net/ethernet/smsc/smc91x.c#L2110">2110</a> <b><i>         * The device will ignore all writes to the enable bit while</i></b>
<a name="L2111" href="source/drivers/net/ethernet/smsc/smc91x.c#L2111">2111</a> <b><i>         * reset is asserted, even if the reset bit is cleared in the</i></b>
<a name="L2112" href="source/drivers/net/ethernet/smsc/smc91x.c#L2112">2112</a> <b><i>         * same write.  Must clear reset first, then enable the device.</i></b>
<a name="L2113" href="source/drivers/net/ethernet/smsc/smc91x.c#L2113">2113</a> <b><i>         */</i></b>
<a name="L2114" href="source/drivers/net/ethernet/smsc/smc91x.c#L2114">2114</a>         <a href="ident?i=writeb">writeb</a>(ecor, <a href="ident?i=addr">addr</a> + (<a href="ident?i=ECOR">ECOR</a> &lt;&lt; <a href="ident?i=SMC_IO_SHIFT">SMC_IO_SHIFT</a>));
<a name="L2115" href="source/drivers/net/ethernet/smsc/smc91x.c#L2115">2115</a>         <a href="ident?i=writeb">writeb</a>(ecor | <a href="ident?i=ECOR_ENABLE">ECOR_ENABLE</a>, <a href="ident?i=addr">addr</a> + (<a href="ident?i=ECOR">ECOR</a> &lt;&lt; <a href="ident?i=SMC_IO_SHIFT">SMC_IO_SHIFT</a>));
<a name="L2116" href="source/drivers/net/ethernet/smsc/smc91x.c#L2116">2116</a> 
<a name="L2117" href="source/drivers/net/ethernet/smsc/smc91x.c#L2117">2117</a>         <b><i>/*</i></b>
<a name="L2118" href="source/drivers/net/ethernet/smsc/smc91x.c#L2118">2118</a> <b><i>         * Set the appropriate byte/word mode.</i></b>
<a name="L2119" href="source/drivers/net/ethernet/smsc/smc91x.c#L2119">2119</a> <b><i>         */</i></b>
<a name="L2120" href="source/drivers/net/ethernet/smsc/smc91x.c#L2120">2120</a>         ecsr = <a href="ident?i=readb">readb</a>(<a href="ident?i=addr">addr</a> + (<a href="ident?i=ECSR">ECSR</a> &lt;&lt; <a href="ident?i=SMC_IO_SHIFT">SMC_IO_SHIFT</a>)) &amp; ~ECSR_IOIS8;
<a name="L2121" href="source/drivers/net/ethernet/smsc/smc91x.c#L2121">2121</a>         if (!<a href="ident?i=SMC_16BIT">SMC_16BIT</a>(<a href="ident?i=lp">lp</a>))
<a name="L2122" href="source/drivers/net/ethernet/smsc/smc91x.c#L2122">2122</a>                 ecsr |= <a href="ident?i=ECSR_IOIS8">ECSR_IOIS8</a>;
<a name="L2123" href="source/drivers/net/ethernet/smsc/smc91x.c#L2123">2123</a>         <a href="ident?i=writeb">writeb</a>(ecsr, <a href="ident?i=addr">addr</a> + (<a href="ident?i=ECSR">ECSR</a> &lt;&lt; <a href="ident?i=SMC_IO_SHIFT">SMC_IO_SHIFT</a>));
<a name="L2124" href="source/drivers/net/ethernet/smsc/smc91x.c#L2124">2124</a>         <a href="ident?i=local_irq_restore">local_irq_restore</a>(<a href="ident?i=flags">flags</a>);
<a name="L2125" href="source/drivers/net/ethernet/smsc/smc91x.c#L2125">2125</a> 
<a name="L2126" href="source/drivers/net/ethernet/smsc/smc91x.c#L2126">2126</a>         <a href="ident?i=iounmap">iounmap</a>(<a href="ident?i=addr">addr</a>);
<a name="L2127" href="source/drivers/net/ethernet/smsc/smc91x.c#L2127">2127</a> 
<a name="L2128" href="source/drivers/net/ethernet/smsc/smc91x.c#L2128">2128</a>         <b><i>/*</i></b>
<a name="L2129" href="source/drivers/net/ethernet/smsc/smc91x.c#L2129">2129</a> <b><i>         * Wait for the chip to wake up.  We could poll the control</i></b>
<a name="L2130" href="source/drivers/net/ethernet/smsc/smc91x.c#L2130">2130</a> <b><i>         * register in the main register space, but that isn't mapped</i></b>
<a name="L2131" href="source/drivers/net/ethernet/smsc/smc91x.c#L2131">2131</a> <b><i>         * yet.  We know this is going to take 750us.</i></b>
<a name="L2132" href="source/drivers/net/ethernet/smsc/smc91x.c#L2132">2132</a> <b><i>         */</i></b>
<a name="L2133" href="source/drivers/net/ethernet/smsc/smc91x.c#L2133">2133</a>         <a href="ident?i=msleep">msleep</a>(1);
<a name="L2134" href="source/drivers/net/ethernet/smsc/smc91x.c#L2134">2134</a> 
<a name="L2135" href="source/drivers/net/ethernet/smsc/smc91x.c#L2135">2135</a>         return 0;
<a name="L2136" href="source/drivers/net/ethernet/smsc/smc91x.c#L2136">2136</a> }
<a name="L2137" href="source/drivers/net/ethernet/smsc/smc91x.c#L2137">2137</a> 
<a name="L2138" href="source/drivers/net/ethernet/smsc/smc91x.c#L2138">2138</a> static int <a href="ident?i=smc_request_attrib">smc_request_attrib</a>(struct <a href="ident?i=platform_device">platform_device</a> *<a href="ident?i=pdev">pdev</a>,
<a name="L2139" href="source/drivers/net/ethernet/smsc/smc91x.c#L2139">2139</a>                               struct <a href="ident?i=net_device">net_device</a> *ndev)
<a name="L2140" href="source/drivers/net/ethernet/smsc/smc91x.c#L2140">2140</a> {
<a name="L2141" href="source/drivers/net/ethernet/smsc/smc91x.c#L2141">2141</a>         struct <a href="ident?i=resource">resource</a> * <a href="ident?i=res">res</a> = <a href="ident?i=platform_get_resource_byname">platform_get_resource_byname</a>(<a href="ident?i=pdev">pdev</a>, <a href="ident?i=IORESOURCE_MEM">IORESOURCE_MEM</a>, <i>"smc91x-attrib"</i>);
<a name="L2142" href="source/drivers/net/ethernet/smsc/smc91x.c#L2142">2142</a>         struct <a href="ident?i=smc_local">smc_local</a> *<a href="ident?i=lp">lp</a> <a href="ident?i=__maybe_unused">__maybe_unused</a> = <a href="ident?i=netdev_priv">netdev_priv</a>(ndev);
<a name="L2143" href="source/drivers/net/ethernet/smsc/smc91x.c#L2143">2143</a> 
<a name="L2144" href="source/drivers/net/ethernet/smsc/smc91x.c#L2144">2144</a>         if (!<a href="ident?i=res">res</a>)
<a name="L2145" href="source/drivers/net/ethernet/smsc/smc91x.c#L2145">2145</a>                 return 0;
<a name="L2146" href="source/drivers/net/ethernet/smsc/smc91x.c#L2146">2146</a> 
<a name="L2147" href="source/drivers/net/ethernet/smsc/smc91x.c#L2147">2147</a>         if (!<a href="ident?i=request_mem_region">request_mem_region</a>(<a href="ident?i=res">res</a>-&gt;<a href="ident?i=start">start</a>, <a href="ident?i=ATTRIB_SIZE">ATTRIB_SIZE</a>, <a href="ident?i=CARDNAME">CARDNAME</a>))
<a name="L2148" href="source/drivers/net/ethernet/smsc/smc91x.c#L2148">2148</a>                 return -<a href="ident?i=EBUSY">EBUSY</a>;
<a name="L2149" href="source/drivers/net/ethernet/smsc/smc91x.c#L2149">2149</a> 
<a name="L2150" href="source/drivers/net/ethernet/smsc/smc91x.c#L2150">2150</a>         return 0;
<a name="L2151" href="source/drivers/net/ethernet/smsc/smc91x.c#L2151">2151</a> }
<a name="L2152" href="source/drivers/net/ethernet/smsc/smc91x.c#L2152">2152</a> 
<a name="L2153" href="source/drivers/net/ethernet/smsc/smc91x.c#L2153">2153</a> static void <a href="ident?i=smc_release_attrib">smc_release_attrib</a>(struct <a href="ident?i=platform_device">platform_device</a> *<a href="ident?i=pdev">pdev</a>,
<a name="L2154" href="source/drivers/net/ethernet/smsc/smc91x.c#L2154">2154</a>                                struct <a href="ident?i=net_device">net_device</a> *ndev)
<a name="L2155" href="source/drivers/net/ethernet/smsc/smc91x.c#L2155">2155</a> {
<a name="L2156" href="source/drivers/net/ethernet/smsc/smc91x.c#L2156">2156</a>         struct <a href="ident?i=resource">resource</a> * <a href="ident?i=res">res</a> = <a href="ident?i=platform_get_resource_byname">platform_get_resource_byname</a>(<a href="ident?i=pdev">pdev</a>, <a href="ident?i=IORESOURCE_MEM">IORESOURCE_MEM</a>, <i>"smc91x-attrib"</i>);
<a name="L2157" href="source/drivers/net/ethernet/smsc/smc91x.c#L2157">2157</a>         struct <a href="ident?i=smc_local">smc_local</a> *<a href="ident?i=lp">lp</a> <a href="ident?i=__maybe_unused">__maybe_unused</a> = <a href="ident?i=netdev_priv">netdev_priv</a>(ndev);
<a name="L2158" href="source/drivers/net/ethernet/smsc/smc91x.c#L2158">2158</a> 
<a name="L2159" href="source/drivers/net/ethernet/smsc/smc91x.c#L2159">2159</a>         if (<a href="ident?i=res">res</a>)
<a name="L2160" href="source/drivers/net/ethernet/smsc/smc91x.c#L2160">2160</a>                 <a href="ident?i=release_mem_region">release_mem_region</a>(<a href="ident?i=res">res</a>-&gt;<a href="ident?i=start">start</a>, <a href="ident?i=ATTRIB_SIZE">ATTRIB_SIZE</a>);
<a name="L2161" href="source/drivers/net/ethernet/smsc/smc91x.c#L2161">2161</a> }
<a name="L2162" href="source/drivers/net/ethernet/smsc/smc91x.c#L2162">2162</a> 
<a name="L2163" href="source/drivers/net/ethernet/smsc/smc91x.c#L2163">2163</a> static inline void <a href="ident?i=smc_request_datacs">smc_request_datacs</a>(struct <a href="ident?i=platform_device">platform_device</a> *<a href="ident?i=pdev">pdev</a>, struct <a href="ident?i=net_device">net_device</a> *ndev)
<a name="L2164" href="source/drivers/net/ethernet/smsc/smc91x.c#L2164">2164</a> {
<a name="L2165" href="source/drivers/net/ethernet/smsc/smc91x.c#L2165">2165</a>         if (<a href="ident?i=SMC_CAN_USE_DATACS">SMC_CAN_USE_DATACS</a>) {
<a name="L2166" href="source/drivers/net/ethernet/smsc/smc91x.c#L2166">2166</a>                 struct <a href="ident?i=resource">resource</a> * <a href="ident?i=res">res</a> = <a href="ident?i=platform_get_resource_byname">platform_get_resource_byname</a>(<a href="ident?i=pdev">pdev</a>, <a href="ident?i=IORESOURCE_MEM">IORESOURCE_MEM</a>, <i>"smc91x-data32"</i>);
<a name="L2167" href="source/drivers/net/ethernet/smsc/smc91x.c#L2167">2167</a>                 struct <a href="ident?i=smc_local">smc_local</a> *<a href="ident?i=lp">lp</a> = <a href="ident?i=netdev_priv">netdev_priv</a>(ndev);
<a name="L2168" href="source/drivers/net/ethernet/smsc/smc91x.c#L2168">2168</a> 
<a name="L2169" href="source/drivers/net/ethernet/smsc/smc91x.c#L2169">2169</a>                 if (!<a href="ident?i=res">res</a>)
<a name="L2170" href="source/drivers/net/ethernet/smsc/smc91x.c#L2170">2170</a>                         return;
<a name="L2171" href="source/drivers/net/ethernet/smsc/smc91x.c#L2171">2171</a> 
<a name="L2172" href="source/drivers/net/ethernet/smsc/smc91x.c#L2172">2172</a>                 if(!<a href="ident?i=request_mem_region">request_mem_region</a>(<a href="ident?i=res">res</a>-&gt;<a href="ident?i=start">start</a>, <a href="ident?i=SMC_DATA_EXTENT">SMC_DATA_EXTENT</a>, <a href="ident?i=CARDNAME">CARDNAME</a>)) {
<a name="L2173" href="source/drivers/net/ethernet/smsc/smc91x.c#L2173">2173</a>                         <a href="ident?i=netdev_info">netdev_info</a>(ndev, <i>"%s: failed to request datacs memory region.\n"</i>,
<a name="L2174" href="source/drivers/net/ethernet/smsc/smc91x.c#L2174">2174</a>                                     <a href="ident?i=CARDNAME">CARDNAME</a>);
<a name="L2175" href="source/drivers/net/ethernet/smsc/smc91x.c#L2175">2175</a>                         return;
<a name="L2176" href="source/drivers/net/ethernet/smsc/smc91x.c#L2176">2176</a>                 }
<a name="L2177" href="source/drivers/net/ethernet/smsc/smc91x.c#L2177">2177</a> 
<a name="L2178" href="source/drivers/net/ethernet/smsc/smc91x.c#L2178">2178</a>                 <a href="ident?i=lp">lp</a>-&gt;datacs = <a href="ident?i=ioremap">ioremap</a>(<a href="ident?i=res">res</a>-&gt;<a href="ident?i=start">start</a>, <a href="ident?i=SMC_DATA_EXTENT">SMC_DATA_EXTENT</a>);
<a name="L2179" href="source/drivers/net/ethernet/smsc/smc91x.c#L2179">2179</a>         }
<a name="L2180" href="source/drivers/net/ethernet/smsc/smc91x.c#L2180">2180</a> }
<a name="L2181" href="source/drivers/net/ethernet/smsc/smc91x.c#L2181">2181</a> 
<a name="L2182" href="source/drivers/net/ethernet/smsc/smc91x.c#L2182">2182</a> static void <a href="ident?i=smc_release_datacs">smc_release_datacs</a>(struct <a href="ident?i=platform_device">platform_device</a> *<a href="ident?i=pdev">pdev</a>, struct <a href="ident?i=net_device">net_device</a> *ndev)
<a name="L2183" href="source/drivers/net/ethernet/smsc/smc91x.c#L2183">2183</a> {
<a name="L2184" href="source/drivers/net/ethernet/smsc/smc91x.c#L2184">2184</a>         if (<a href="ident?i=SMC_CAN_USE_DATACS">SMC_CAN_USE_DATACS</a>) {
<a name="L2185" href="source/drivers/net/ethernet/smsc/smc91x.c#L2185">2185</a>                 struct <a href="ident?i=smc_local">smc_local</a> *<a href="ident?i=lp">lp</a> = <a href="ident?i=netdev_priv">netdev_priv</a>(ndev);
<a name="L2186" href="source/drivers/net/ethernet/smsc/smc91x.c#L2186">2186</a>                 struct <a href="ident?i=resource">resource</a> * <a href="ident?i=res">res</a> = <a href="ident?i=platform_get_resource_byname">platform_get_resource_byname</a>(<a href="ident?i=pdev">pdev</a>, <a href="ident?i=IORESOURCE_MEM">IORESOURCE_MEM</a>, <i>"smc91x-data32"</i>);
<a name="L2187" href="source/drivers/net/ethernet/smsc/smc91x.c#L2187">2187</a> 
<a name="L2188" href="source/drivers/net/ethernet/smsc/smc91x.c#L2188">2188</a>                 if (<a href="ident?i=lp">lp</a>-&gt;datacs)
<a name="L2189" href="source/drivers/net/ethernet/smsc/smc91x.c#L2189">2189</a>                         <a href="ident?i=iounmap">iounmap</a>(<a href="ident?i=lp">lp</a>-&gt;datacs);
<a name="L2190" href="source/drivers/net/ethernet/smsc/smc91x.c#L2190">2190</a> 
<a name="L2191" href="source/drivers/net/ethernet/smsc/smc91x.c#L2191">2191</a>                 <a href="ident?i=lp">lp</a>-&gt;datacs = <a href="ident?i=NULL">NULL</a>;
<a name="L2192" href="source/drivers/net/ethernet/smsc/smc91x.c#L2192">2192</a> 
<a name="L2193" href="source/drivers/net/ethernet/smsc/smc91x.c#L2193">2193</a>                 if (<a href="ident?i=res">res</a>)
<a name="L2194" href="source/drivers/net/ethernet/smsc/smc91x.c#L2194">2194</a>                         <a href="ident?i=release_mem_region">release_mem_region</a>(<a href="ident?i=res">res</a>-&gt;<a href="ident?i=start">start</a>, <a href="ident?i=SMC_DATA_EXTENT">SMC_DATA_EXTENT</a>);
<a name="L2195" href="source/drivers/net/ethernet/smsc/smc91x.c#L2195">2195</a>         }
<a name="L2196" href="source/drivers/net/ethernet/smsc/smc91x.c#L2196">2196</a> }
<a name="L2197" href="source/drivers/net/ethernet/smsc/smc91x.c#L2197">2197</a> 
<a name="L2198" href="source/drivers/net/ethernet/smsc/smc91x.c#L2198">2198</a> static const struct <a href="ident?i=acpi_device_id">acpi_device_id</a> <a href="ident?i=smc91x_acpi_match">smc91x_acpi_match</a>[] = {
<a name="L2199" href="source/drivers/net/ethernet/smsc/smc91x.c#L2199">2199</a>         { <i>"LNRO0003"</i>, 0 },
<a name="L2200" href="source/drivers/net/ethernet/smsc/smc91x.c#L2200">2200</a>         { }
<a name="L2201" href="source/drivers/net/ethernet/smsc/smc91x.c#L2201">2201</a> };
<a name="L2202" href="source/drivers/net/ethernet/smsc/smc91x.c#L2202">2202</a> <a href="ident?i=MODULE_DEVICE_TABLE">MODULE_DEVICE_TABLE</a>(acpi, <a href="ident?i=smc91x_acpi_match">smc91x_acpi_match</a>);
<a name="L2203" href="source/drivers/net/ethernet/smsc/smc91x.c#L2203">2203</a> 
<a name="L2204" href="source/drivers/net/ethernet/smsc/smc91x.c#L2204">2204</a> #if <a href="ident?i=IS_BUILTIN">IS_BUILTIN</a>(CONFIG_OF)
<a name="L2205" href="source/drivers/net/ethernet/smsc/smc91x.c#L2205">2205</a> static const struct <a href="ident?i=of_device_id">of_device_id</a> <a href="ident?i=smc91x_match">smc91x_match</a>[] = {
<a name="L2206" href="source/drivers/net/ethernet/smsc/smc91x.c#L2206">2206</a>         { .compatible = <i>"smsc,lan91c94"</i>, },
<a name="L2207" href="source/drivers/net/ethernet/smsc/smc91x.c#L2207">2207</a>         { .compatible = <i>"smsc,lan91c111"</i>, },
<a name="L2208" href="source/drivers/net/ethernet/smsc/smc91x.c#L2208">2208</a>         {},
<a name="L2209" href="source/drivers/net/ethernet/smsc/smc91x.c#L2209">2209</a> };
<a name="L2210" href="source/drivers/net/ethernet/smsc/smc91x.c#L2210">2210</a> <a href="ident?i=MODULE_DEVICE_TABLE">MODULE_DEVICE_TABLE</a>(of, <a href="ident?i=smc91x_match">smc91x_match</a>);
<a name="L2211" href="source/drivers/net/ethernet/smsc/smc91x.c#L2211">2211</a> 
<a name="L2212" href="source/drivers/net/ethernet/smsc/smc91x.c#L2212">2212</a> <b><i>/**</i></b>
<a name="L2213" href="source/drivers/net/ethernet/smsc/smc91x.c#L2213">2213</a> <b><i> * of_try_set_control_gpio - configure a gpio if it exists</i></b>
<a name="L2214" href="source/drivers/net/ethernet/smsc/smc91x.c#L2214">2214</a> <b><i> */</i></b>
<a name="L2215" href="source/drivers/net/ethernet/smsc/smc91x.c#L2215">2215</a> static int <a href="ident?i=try_toggle_control_gpio">try_toggle_control_gpio</a>(struct <a href="ident?i=device">device</a> *<a href="ident?i=dev">dev</a>,
<a name="L2216" href="source/drivers/net/ethernet/smsc/smc91x.c#L2216">2216</a>                                    struct <a href="ident?i=gpio_desc">gpio_desc</a> **<a href="ident?i=desc">desc</a>,
<a name="L2217" href="source/drivers/net/ethernet/smsc/smc91x.c#L2217">2217</a>                                    const char *<a href="ident?i=name">name</a>, int <a href="ident?i=index">index</a>,
<a name="L2218" href="source/drivers/net/ethernet/smsc/smc91x.c#L2218">2218</a>                                    int <a href="ident?i=value">value</a>, unsigned int nsdelay)
<a name="L2219" href="source/drivers/net/ethernet/smsc/smc91x.c#L2219">2219</a> {
<a name="L2220" href="source/drivers/net/ethernet/smsc/smc91x.c#L2220">2220</a>         struct <a href="ident?i=gpio_desc">gpio_desc</a> *<a href="ident?i=gpio">gpio</a> = *<a href="ident?i=desc">desc</a>;
<a name="L2221" href="source/drivers/net/ethernet/smsc/smc91x.c#L2221">2221</a>         enum <a href="ident?i=gpiod_flags">gpiod_flags</a> <a href="ident?i=flags">flags</a> = <a href="ident?i=value">value</a> ? GPIOD_OUT_LOW : GPIOD_OUT_HIGH;
<a name="L2222" href="source/drivers/net/ethernet/smsc/smc91x.c#L2222">2222</a> 
<a name="L2223" href="source/drivers/net/ethernet/smsc/smc91x.c#L2223">2223</a>         <a href="ident?i=gpio">gpio</a> = <a href="ident?i=devm_gpiod_get_index_optional">devm_gpiod_get_index_optional</a>(<a href="ident?i=dev">dev</a>, <a href="ident?i=name">name</a>, <a href="ident?i=index">index</a>, <a href="ident?i=flags">flags</a>);
<a name="L2224" href="source/drivers/net/ethernet/smsc/smc91x.c#L2224">2224</a>         if (<a href="ident?i=IS_ERR">IS_ERR</a>(<a href="ident?i=gpio">gpio</a>))
<a name="L2225" href="source/drivers/net/ethernet/smsc/smc91x.c#L2225">2225</a>                 return <a href="ident?i=PTR_ERR">PTR_ERR</a>(<a href="ident?i=gpio">gpio</a>);
<a name="L2226" href="source/drivers/net/ethernet/smsc/smc91x.c#L2226">2226</a> 
<a name="L2227" href="source/drivers/net/ethernet/smsc/smc91x.c#L2227">2227</a>         if (<a href="ident?i=gpio">gpio</a>) {
<a name="L2228" href="source/drivers/net/ethernet/smsc/smc91x.c#L2228">2228</a>                 if (nsdelay)
<a name="L2229" href="source/drivers/net/ethernet/smsc/smc91x.c#L2229">2229</a>                         <a href="ident?i=usleep_range">usleep_range</a>(nsdelay, 2 * nsdelay);
<a name="L2230" href="source/drivers/net/ethernet/smsc/smc91x.c#L2230">2230</a>                 <a href="ident?i=gpiod_set_value_cansleep">gpiod_set_value_cansleep</a>(<a href="ident?i=gpio">gpio</a>, <a href="ident?i=value">value</a>);
<a name="L2231" href="source/drivers/net/ethernet/smsc/smc91x.c#L2231">2231</a>         }
<a name="L2232" href="source/drivers/net/ethernet/smsc/smc91x.c#L2232">2232</a>         *<a href="ident?i=desc">desc</a> = <a href="ident?i=gpio">gpio</a>;
<a name="L2233" href="source/drivers/net/ethernet/smsc/smc91x.c#L2233">2233</a> 
<a name="L2234" href="source/drivers/net/ethernet/smsc/smc91x.c#L2234">2234</a>         return 0;
<a name="L2235" href="source/drivers/net/ethernet/smsc/smc91x.c#L2235">2235</a> }
<a name="L2236" href="source/drivers/net/ethernet/smsc/smc91x.c#L2236">2236</a> #endif
<a name="L2237" href="source/drivers/net/ethernet/smsc/smc91x.c#L2237">2237</a> 
<a name="L2238" href="source/drivers/net/ethernet/smsc/smc91x.c#L2238">2238</a> <b><i>/*</i></b>
<a name="L2239" href="source/drivers/net/ethernet/smsc/smc91x.c#L2239">2239</a> <b><i> * smc_init(void)</i></b>
<a name="L2240" href="source/drivers/net/ethernet/smsc/smc91x.c#L2240">2240</a> <b><i> *   Input parameters:</i></b>
<a name="L2241" href="source/drivers/net/ethernet/smsc/smc91x.c#L2241">2241</a> <b><i> *      dev-&gt;base_addr == 0, try to find all possible locations</i></b>
<a name="L2242" href="source/drivers/net/ethernet/smsc/smc91x.c#L2242">2242</a> <b><i> *      dev-&gt;base_addr &gt; 0x1ff, this is the address to check</i></b>
<a name="L2243" href="source/drivers/net/ethernet/smsc/smc91x.c#L2243">2243</a> <b><i> *      dev-&gt;base_addr == &lt;anything else&gt;, return failure code</i></b>
<a name="L2244" href="source/drivers/net/ethernet/smsc/smc91x.c#L2244">2244</a> <b><i> *</i></b>
<a name="L2245" href="source/drivers/net/ethernet/smsc/smc91x.c#L2245">2245</a> <b><i> *   Output:</i></b>
<a name="L2246" href="source/drivers/net/ethernet/smsc/smc91x.c#L2246">2246</a> <b><i> *      0 --&gt; there is a device</i></b>
<a name="L2247" href="source/drivers/net/ethernet/smsc/smc91x.c#L2247">2247</a> <b><i> *      anything else, error</i></b>
<a name="L2248" href="source/drivers/net/ethernet/smsc/smc91x.c#L2248">2248</a> <b><i> */</i></b>
<a name="L2249" href="source/drivers/net/ethernet/smsc/smc91x.c#L2249">2249</a> static int <a href="ident?i=smc_drv_probe">smc_drv_probe</a>(struct <a href="ident?i=platform_device">platform_device</a> *<a href="ident?i=pdev">pdev</a>)
<a name="L2250" href="source/drivers/net/ethernet/smsc/smc91x.c#L2250">2250</a> {
<a name="L2251" href="source/drivers/net/ethernet/smsc/smc91x.c#L2251">2251</a>         struct <a href="ident?i=smc91x_platdata">smc91x_platdata</a> *<a href="ident?i=pd">pd</a> = <a href="ident?i=dev_get_platdata">dev_get_platdata</a>(&amp;<a href="ident?i=pdev">pdev</a>-&gt;<a href="ident?i=dev">dev</a>);
<a name="L2252" href="source/drivers/net/ethernet/smsc/smc91x.c#L2252">2252</a>         const struct <a href="ident?i=of_device_id">of_device_id</a> *<a href="ident?i=match">match</a> = <a href="ident?i=NULL">NULL</a>;
<a name="L2253" href="source/drivers/net/ethernet/smsc/smc91x.c#L2253">2253</a>         struct <a href="ident?i=smc_local">smc_local</a> *<a href="ident?i=lp">lp</a>;
<a name="L2254" href="source/drivers/net/ethernet/smsc/smc91x.c#L2254">2254</a>         struct <a href="ident?i=net_device">net_device</a> *ndev;
<a name="L2255" href="source/drivers/net/ethernet/smsc/smc91x.c#L2255">2255</a>         struct <a href="ident?i=resource">resource</a> *<a href="ident?i=res">res</a>;
<a name="L2256" href="source/drivers/net/ethernet/smsc/smc91x.c#L2256">2256</a>         unsigned int <a href="ident?i=__iomem">__iomem</a> *<a href="ident?i=addr">addr</a>;
<a name="L2257" href="source/drivers/net/ethernet/smsc/smc91x.c#L2257">2257</a>         unsigned long irq_flags = <a href="ident?i=SMC_IRQ_FLAGS">SMC_IRQ_FLAGS</a>;
<a name="L2258" href="source/drivers/net/ethernet/smsc/smc91x.c#L2258">2258</a>         unsigned long irq_resflags;
<a name="L2259" href="source/drivers/net/ethernet/smsc/smc91x.c#L2259">2259</a>         int <a href="ident?i=ret">ret</a>;
<a name="L2260" href="source/drivers/net/ethernet/smsc/smc91x.c#L2260">2260</a> 
<a name="L2261" href="source/drivers/net/ethernet/smsc/smc91x.c#L2261">2261</a>         ndev = <a href="ident?i=alloc_etherdev">alloc_etherdev</a>(sizeof(struct <a href="ident?i=smc_local">smc_local</a>));
<a name="L2262" href="source/drivers/net/ethernet/smsc/smc91x.c#L2262">2262</a>         if (!ndev) {
<a name="L2263" href="source/drivers/net/ethernet/smsc/smc91x.c#L2263">2263</a>                 <a href="ident?i=ret">ret</a> = -<a href="ident?i=ENOMEM">ENOMEM</a>;
<a name="L2264" href="source/drivers/net/ethernet/smsc/smc91x.c#L2264">2264</a>                 goto <a href="ident?i=out">out</a>;
<a name="L2265" href="source/drivers/net/ethernet/smsc/smc91x.c#L2265">2265</a>         }
<a name="L2266" href="source/drivers/net/ethernet/smsc/smc91x.c#L2266">2266</a>         <a href="ident?i=SET_NETDEV_DEV">SET_NETDEV_DEV</a>(ndev, &amp;<a href="ident?i=pdev">pdev</a>-&gt;<a href="ident?i=dev">dev</a>);
<a name="L2267" href="source/drivers/net/ethernet/smsc/smc91x.c#L2267">2267</a> 
<a name="L2268" href="source/drivers/net/ethernet/smsc/smc91x.c#L2268">2268</a>         <b><i>/* get configuration from platform data, only allow use of</i></b>
<a name="L2269" href="source/drivers/net/ethernet/smsc/smc91x.c#L2269">2269</a> <b><i>         * bus width if both SMC_CAN_USE_xxx and SMC91X_USE_xxx are set.</i></b>
<a name="L2270" href="source/drivers/net/ethernet/smsc/smc91x.c#L2270">2270</a> <b><i>         */</i></b>
<a name="L2271" href="source/drivers/net/ethernet/smsc/smc91x.c#L2271">2271</a> 
<a name="L2272" href="source/drivers/net/ethernet/smsc/smc91x.c#L2272">2272</a>         <a href="ident?i=lp">lp</a> = <a href="ident?i=netdev_priv">netdev_priv</a>(ndev);
<a name="L2273" href="source/drivers/net/ethernet/smsc/smc91x.c#L2273">2273</a>         <a href="ident?i=lp">lp</a>-&gt;<a href="ident?i=cfg">cfg</a>.<a href="ident?i=flags">flags</a> = 0;
<a name="L2274" href="source/drivers/net/ethernet/smsc/smc91x.c#L2274">2274</a> 
<a name="L2275" href="source/drivers/net/ethernet/smsc/smc91x.c#L2275">2275</a>         if (<a href="ident?i=pd">pd</a>) {
<a name="L2276" href="source/drivers/net/ethernet/smsc/smc91x.c#L2276">2276</a>                 <a href="ident?i=memcpy">memcpy</a>(&amp;<a href="ident?i=lp">lp</a>-&gt;<a href="ident?i=cfg">cfg</a>, <a href="ident?i=pd">pd</a>, sizeof(<a href="ident?i=lp">lp</a>-&gt;<a href="ident?i=cfg">cfg</a>));
<a name="L2277" href="source/drivers/net/ethernet/smsc/smc91x.c#L2277">2277</a>                 <a href="ident?i=lp">lp</a>-&gt;io_shift = <a href="ident?i=SMC91X_IO_SHIFT">SMC91X_IO_SHIFT</a>(<a href="ident?i=lp">lp</a>-&gt;<a href="ident?i=cfg">cfg</a>.<a href="ident?i=flags">flags</a>);
<a name="L2278" href="source/drivers/net/ethernet/smsc/smc91x.c#L2278">2278</a> 
<a name="L2279" href="source/drivers/net/ethernet/smsc/smc91x.c#L2279">2279</a>                 if (!<a href="ident?i=SMC_8BIT">SMC_8BIT</a>(<a href="ident?i=lp">lp</a>) &amp;&amp; !<a href="ident?i=SMC_16BIT">SMC_16BIT</a>(<a href="ident?i=lp">lp</a>)) {
<a name="L2280" href="source/drivers/net/ethernet/smsc/smc91x.c#L2280">2280</a>                         <a href="ident?i=dev_err">dev_err</a>(&amp;<a href="ident?i=pdev">pdev</a>-&gt;<a href="ident?i=dev">dev</a>,
<a name="L2281" href="source/drivers/net/ethernet/smsc/smc91x.c#L2281">2281</a>                                 <i>"at least one of 8-bit or 16-bit access support is required.\n"</i>);
<a name="L2282" href="source/drivers/net/ethernet/smsc/smc91x.c#L2282">2282</a>                         <a href="ident?i=ret">ret</a> = -<a href="ident?i=ENXIO">ENXIO</a>;
<a name="L2283" href="source/drivers/net/ethernet/smsc/smc91x.c#L2283">2283</a>                         goto out_free_netdev;
<a name="L2284" href="source/drivers/net/ethernet/smsc/smc91x.c#L2284">2284</a>                 }
<a name="L2285" href="source/drivers/net/ethernet/smsc/smc91x.c#L2285">2285</a>         }
<a name="L2286" href="source/drivers/net/ethernet/smsc/smc91x.c#L2286">2286</a> 
<a name="L2287" href="source/drivers/net/ethernet/smsc/smc91x.c#L2287">2287</a> #if <a href="ident?i=IS_BUILTIN">IS_BUILTIN</a>(CONFIG_OF)
<a name="L2288" href="source/drivers/net/ethernet/smsc/smc91x.c#L2288">2288</a>         <a href="ident?i=match">match</a> = <a href="ident?i=of_match_device">of_match_device</a>(<a href="ident?i=of_match_ptr">of_match_ptr</a>(<a href="ident?i=smc91x_match">smc91x_match</a>), &amp;<a href="ident?i=pdev">pdev</a>-&gt;<a href="ident?i=dev">dev</a>);
<a name="L2289" href="source/drivers/net/ethernet/smsc/smc91x.c#L2289">2289</a>         if (<a href="ident?i=match">match</a>) {
<a name="L2290" href="source/drivers/net/ethernet/smsc/smc91x.c#L2290">2290</a>                 <a href="ident?i=u32">u32</a> <a href="ident?i=val">val</a>;
<a name="L2291" href="source/drivers/net/ethernet/smsc/smc91x.c#L2291">2291</a> 
<a name="L2292" href="source/drivers/net/ethernet/smsc/smc91x.c#L2292">2292</a>                 <b><i>/* Optional pwrdwn GPIO configured? */</i></b>
<a name="L2293" href="source/drivers/net/ethernet/smsc/smc91x.c#L2293">2293</a>                 <a href="ident?i=ret">ret</a> = <a href="ident?i=try_toggle_control_gpio">try_toggle_control_gpio</a>(&amp;<a href="ident?i=pdev">pdev</a>-&gt;<a href="ident?i=dev">dev</a>, &amp;<a href="ident?i=lp">lp</a>-&gt;power_gpio,
<a name="L2294" href="source/drivers/net/ethernet/smsc/smc91x.c#L2294">2294</a>                                               <i>"power"</i>, 0, 0, 100);
<a name="L2295" href="source/drivers/net/ethernet/smsc/smc91x.c#L2295">2295</a>                 if (<a href="ident?i=ret">ret</a>)
<a name="L2296" href="source/drivers/net/ethernet/smsc/smc91x.c#L2296">2296</a>                         return <a href="ident?i=ret">ret</a>;
<a name="L2297" href="source/drivers/net/ethernet/smsc/smc91x.c#L2297">2297</a> 
<a name="L2298" href="source/drivers/net/ethernet/smsc/smc91x.c#L2298">2298</a>                 <b><i>/*</i></b>
<a name="L2299" href="source/drivers/net/ethernet/smsc/smc91x.c#L2299">2299</a> <b><i>                 * Optional reset GPIO configured? Minimum 100 ns reset needed</i></b>
<a name="L2300" href="source/drivers/net/ethernet/smsc/smc91x.c#L2300">2300</a> <b><i>                 * according to LAN91C96 datasheet page 14.</i></b>
<a name="L2301" href="source/drivers/net/ethernet/smsc/smc91x.c#L2301">2301</a> <b><i>                 */</i></b>
<a name="L2302" href="source/drivers/net/ethernet/smsc/smc91x.c#L2302">2302</a>                 <a href="ident?i=ret">ret</a> = <a href="ident?i=try_toggle_control_gpio">try_toggle_control_gpio</a>(&amp;<a href="ident?i=pdev">pdev</a>-&gt;<a href="ident?i=dev">dev</a>, &amp;<a href="ident?i=lp">lp</a>-&gt;<a href="ident?i=reset_gpio">reset_gpio</a>,
<a name="L2303" href="source/drivers/net/ethernet/smsc/smc91x.c#L2303">2303</a>                                               <i>"reset"</i>, 0, 0, 100);
<a name="L2304" href="source/drivers/net/ethernet/smsc/smc91x.c#L2304">2304</a>                 if (<a href="ident?i=ret">ret</a>)
<a name="L2305" href="source/drivers/net/ethernet/smsc/smc91x.c#L2305">2305</a>                         return <a href="ident?i=ret">ret</a>;
<a name="L2306" href="source/drivers/net/ethernet/smsc/smc91x.c#L2306">2306</a> 
<a name="L2307" href="source/drivers/net/ethernet/smsc/smc91x.c#L2307">2307</a>                 <b><i>/*</i></b>
<a name="L2308" href="source/drivers/net/ethernet/smsc/smc91x.c#L2308">2308</a> <b><i>                 * Need to wait for optional EEPROM to load, max 750 us according</i></b>
<a name="L2309" href="source/drivers/net/ethernet/smsc/smc91x.c#L2309">2309</a> <b><i>                 * to LAN91C96 datasheet page 55.</i></b>
<a name="L2310" href="source/drivers/net/ethernet/smsc/smc91x.c#L2310">2310</a> <b><i>                 */</i></b>
<a name="L2311" href="source/drivers/net/ethernet/smsc/smc91x.c#L2311">2311</a>                 if (<a href="ident?i=lp">lp</a>-&gt;<a href="ident?i=reset_gpio">reset_gpio</a>)
<a name="L2312" href="source/drivers/net/ethernet/smsc/smc91x.c#L2312">2312</a>                         <a href="ident?i=usleep_range">usleep_range</a>(750, 1000);
<a name="L2313" href="source/drivers/net/ethernet/smsc/smc91x.c#L2313">2313</a> 
<a name="L2314" href="source/drivers/net/ethernet/smsc/smc91x.c#L2314">2314</a>                 <b><i>/* Combination of IO widths supported, default to 16-bit */</i></b>
<a name="L2315" href="source/drivers/net/ethernet/smsc/smc91x.c#L2315">2315</a>                 if (!<a href="ident?i=device_property_read_u32">device_property_read_u32</a>(&amp;<a href="ident?i=pdev">pdev</a>-&gt;<a href="ident?i=dev">dev</a>, <i>"reg-io-width"</i>,
<a name="L2316" href="source/drivers/net/ethernet/smsc/smc91x.c#L2316">2316</a>                                               &amp;<a href="ident?i=val">val</a>)) {
<a name="L2317" href="source/drivers/net/ethernet/smsc/smc91x.c#L2317">2317</a>                         if (<a href="ident?i=val">val</a> &amp; 1)
<a name="L2318" href="source/drivers/net/ethernet/smsc/smc91x.c#L2318">2318</a>                                 <a href="ident?i=lp">lp</a>-&gt;<a href="ident?i=cfg">cfg</a>.<a href="ident?i=flags">flags</a> |= <a href="ident?i=SMC91X_USE_8BIT">SMC91X_USE_8BIT</a>;
<a name="L2319" href="source/drivers/net/ethernet/smsc/smc91x.c#L2319">2319</a>                         if ((<a href="ident?i=val">val</a> == 0) || (<a href="ident?i=val">val</a> &amp; 2))
<a name="L2320" href="source/drivers/net/ethernet/smsc/smc91x.c#L2320">2320</a>                                 <a href="ident?i=lp">lp</a>-&gt;<a href="ident?i=cfg">cfg</a>.<a href="ident?i=flags">flags</a> |= <a href="ident?i=SMC91X_USE_16BIT">SMC91X_USE_16BIT</a>;
<a name="L2321" href="source/drivers/net/ethernet/smsc/smc91x.c#L2321">2321</a>                         if (<a href="ident?i=val">val</a> &amp; 4)
<a name="L2322" href="source/drivers/net/ethernet/smsc/smc91x.c#L2322">2322</a>                                 <a href="ident?i=lp">lp</a>-&gt;<a href="ident?i=cfg">cfg</a>.<a href="ident?i=flags">flags</a> |= <a href="ident?i=SMC91X_USE_32BIT">SMC91X_USE_32BIT</a>;
<a name="L2323" href="source/drivers/net/ethernet/smsc/smc91x.c#L2323">2323</a>                 } else {
<a name="L2324" href="source/drivers/net/ethernet/smsc/smc91x.c#L2324">2324</a>                         <a href="ident?i=lp">lp</a>-&gt;<a href="ident?i=cfg">cfg</a>.<a href="ident?i=flags">flags</a> |= <a href="ident?i=SMC91X_USE_16BIT">SMC91X_USE_16BIT</a>;
<a name="L2325" href="source/drivers/net/ethernet/smsc/smc91x.c#L2325">2325</a>                 }
<a name="L2326" href="source/drivers/net/ethernet/smsc/smc91x.c#L2326">2326</a>         }
<a name="L2327" href="source/drivers/net/ethernet/smsc/smc91x.c#L2327">2327</a> #endif
<a name="L2328" href="source/drivers/net/ethernet/smsc/smc91x.c#L2328">2328</a> 
<a name="L2329" href="source/drivers/net/ethernet/smsc/smc91x.c#L2329">2329</a>         if (!<a href="ident?i=pd">pd</a> &amp;&amp; !<a href="ident?i=match">match</a>) {
<a name="L2330" href="source/drivers/net/ethernet/smsc/smc91x.c#L2330">2330</a>                 <a href="ident?i=lp">lp</a>-&gt;<a href="ident?i=cfg">cfg</a>.<a href="ident?i=flags">flags</a> |= (<a href="ident?i=SMC_CAN_USE_8BIT">SMC_CAN_USE_8BIT</a>)  ? <a href="ident?i=SMC91X_USE_8BIT">SMC91X_USE_8BIT</a>  : 0;
<a name="L2331" href="source/drivers/net/ethernet/smsc/smc91x.c#L2331">2331</a>                 <a href="ident?i=lp">lp</a>-&gt;<a href="ident?i=cfg">cfg</a>.<a href="ident?i=flags">flags</a> |= (<a href="ident?i=SMC_CAN_USE_16BIT">SMC_CAN_USE_16BIT</a>) ? <a href="ident?i=SMC91X_USE_16BIT">SMC91X_USE_16BIT</a> : 0;
<a name="L2332" href="source/drivers/net/ethernet/smsc/smc91x.c#L2332">2332</a>                 <a href="ident?i=lp">lp</a>-&gt;<a href="ident?i=cfg">cfg</a>.<a href="ident?i=flags">flags</a> |= (<a href="ident?i=SMC_CAN_USE_32BIT">SMC_CAN_USE_32BIT</a>) ? <a href="ident?i=SMC91X_USE_32BIT">SMC91X_USE_32BIT</a> : 0;
<a name="L2333" href="source/drivers/net/ethernet/smsc/smc91x.c#L2333">2333</a>                 <a href="ident?i=lp">lp</a>-&gt;<a href="ident?i=cfg">cfg</a>.<a href="ident?i=flags">flags</a> |= (<a href="ident?i=nowait">nowait</a>) ? <a href="ident?i=SMC91X_NOWAIT">SMC91X_NOWAIT</a> : 0;
<a name="L2334" href="source/drivers/net/ethernet/smsc/smc91x.c#L2334">2334</a>         }
<a name="L2335" href="source/drivers/net/ethernet/smsc/smc91x.c#L2335">2335</a> 
<a name="L2336" href="source/drivers/net/ethernet/smsc/smc91x.c#L2336">2336</a>         if (!<a href="ident?i=lp">lp</a>-&gt;<a href="ident?i=cfg">cfg</a>.leda &amp;&amp; !<a href="ident?i=lp">lp</a>-&gt;<a href="ident?i=cfg">cfg</a>.ledb) {
<a name="L2337" href="source/drivers/net/ethernet/smsc/smc91x.c#L2337">2337</a>                 <a href="ident?i=lp">lp</a>-&gt;<a href="ident?i=cfg">cfg</a>.leda = <a href="ident?i=RPC_LSA_DEFAULT">RPC_LSA_DEFAULT</a>;
<a name="L2338" href="source/drivers/net/ethernet/smsc/smc91x.c#L2338">2338</a>                 <a href="ident?i=lp">lp</a>-&gt;<a href="ident?i=cfg">cfg</a>.ledb = <a href="ident?i=RPC_LSB_DEFAULT">RPC_LSB_DEFAULT</a>;
<a name="L2339" href="source/drivers/net/ethernet/smsc/smc91x.c#L2339">2339</a>         }
<a name="L2340" href="source/drivers/net/ethernet/smsc/smc91x.c#L2340">2340</a> 
<a name="L2341" href="source/drivers/net/ethernet/smsc/smc91x.c#L2341">2341</a>         ndev-&gt;<a href="ident?i=dma">dma</a> = (unsigned char)-1;
<a name="L2342" href="source/drivers/net/ethernet/smsc/smc91x.c#L2342">2342</a> 
<a name="L2343" href="source/drivers/net/ethernet/smsc/smc91x.c#L2343">2343</a>         <a href="ident?i=res">res</a> = <a href="ident?i=platform_get_resource_byname">platform_get_resource_byname</a>(<a href="ident?i=pdev">pdev</a>, <a href="ident?i=IORESOURCE_MEM">IORESOURCE_MEM</a>, <i>"smc91x-regs"</i>);
<a name="L2344" href="source/drivers/net/ethernet/smsc/smc91x.c#L2344">2344</a>         if (!<a href="ident?i=res">res</a>)
<a name="L2345" href="source/drivers/net/ethernet/smsc/smc91x.c#L2345">2345</a>                 <a href="ident?i=res">res</a> = <a href="ident?i=platform_get_resource">platform_get_resource</a>(<a href="ident?i=pdev">pdev</a>, <a href="ident?i=IORESOURCE_MEM">IORESOURCE_MEM</a>, 0);
<a name="L2346" href="source/drivers/net/ethernet/smsc/smc91x.c#L2346">2346</a>         if (!<a href="ident?i=res">res</a>) {
<a name="L2347" href="source/drivers/net/ethernet/smsc/smc91x.c#L2347">2347</a>                 <a href="ident?i=ret">ret</a> = -<a href="ident?i=ENODEV">ENODEV</a>;
<a name="L2348" href="source/drivers/net/ethernet/smsc/smc91x.c#L2348">2348</a>                 goto out_free_netdev;
<a name="L2349" href="source/drivers/net/ethernet/smsc/smc91x.c#L2349">2349</a>         }
<a name="L2350" href="source/drivers/net/ethernet/smsc/smc91x.c#L2350">2350</a> 
<a name="L2351" href="source/drivers/net/ethernet/smsc/smc91x.c#L2351">2351</a> 
<a name="L2352" href="source/drivers/net/ethernet/smsc/smc91x.c#L2352">2352</a>         if (!<a href="ident?i=request_mem_region">request_mem_region</a>(<a href="ident?i=res">res</a>-&gt;<a href="ident?i=start">start</a>, <a href="ident?i=SMC_IO_EXTENT">SMC_IO_EXTENT</a>, <a href="ident?i=CARDNAME">CARDNAME</a>)) {
<a name="L2353" href="source/drivers/net/ethernet/smsc/smc91x.c#L2353">2353</a>                 <a href="ident?i=ret">ret</a> = -<a href="ident?i=EBUSY">EBUSY</a>;
<a name="L2354" href="source/drivers/net/ethernet/smsc/smc91x.c#L2354">2354</a>                 goto out_free_netdev;
<a name="L2355" href="source/drivers/net/ethernet/smsc/smc91x.c#L2355">2355</a>         }
<a name="L2356" href="source/drivers/net/ethernet/smsc/smc91x.c#L2356">2356</a> 
<a name="L2357" href="source/drivers/net/ethernet/smsc/smc91x.c#L2357">2357</a>         ndev-&gt;<a href="ident?i=irq">irq</a> = <a href="ident?i=platform_get_irq">platform_get_irq</a>(<a href="ident?i=pdev">pdev</a>, 0);
<a name="L2358" href="source/drivers/net/ethernet/smsc/smc91x.c#L2358">2358</a>         if (ndev-&gt;<a href="ident?i=irq">irq</a> &lt; 0) {
<a name="L2359" href="source/drivers/net/ethernet/smsc/smc91x.c#L2359">2359</a>                 <a href="ident?i=ret">ret</a> = ndev-&gt;<a href="ident?i=irq">irq</a>;
<a name="L2360" href="source/drivers/net/ethernet/smsc/smc91x.c#L2360">2360</a>                 goto out_release_io;
<a name="L2361" href="source/drivers/net/ethernet/smsc/smc91x.c#L2361">2361</a>         }
<a name="L2362" href="source/drivers/net/ethernet/smsc/smc91x.c#L2362">2362</a>         <b><i>/*</i></b>
<a name="L2363" href="source/drivers/net/ethernet/smsc/smc91x.c#L2363">2363</a> <b><i>         * If this platform does not specify any special irqflags, or if</i></b>
<a name="L2364" href="source/drivers/net/ethernet/smsc/smc91x.c#L2364">2364</a> <b><i>         * the resource supplies a trigger, override the irqflags with</i></b>
<a name="L2365" href="source/drivers/net/ethernet/smsc/smc91x.c#L2365">2365</a> <b><i>         * the trigger flags from the resource.</i></b>
<a name="L2366" href="source/drivers/net/ethernet/smsc/smc91x.c#L2366">2366</a> <b><i>         */</i></b>
<a name="L2367" href="source/drivers/net/ethernet/smsc/smc91x.c#L2367">2367</a>         irq_resflags = <a href="ident?i=irqd_get_trigger_type">irqd_get_trigger_type</a>(<a href="ident?i=irq_get_irq_data">irq_get_irq_data</a>(ndev-&gt;<a href="ident?i=irq">irq</a>));
<a name="L2368" href="source/drivers/net/ethernet/smsc/smc91x.c#L2368">2368</a>         if (irq_flags == -1 || irq_resflags &amp; <a href="ident?i=IRQF_TRIGGER_MASK">IRQF_TRIGGER_MASK</a>)
<a name="L2369" href="source/drivers/net/ethernet/smsc/smc91x.c#L2369">2369</a>                 irq_flags = irq_resflags &amp; <a href="ident?i=IRQF_TRIGGER_MASK">IRQF_TRIGGER_MASK</a>;
<a name="L2370" href="source/drivers/net/ethernet/smsc/smc91x.c#L2370">2370</a> 
<a name="L2371" href="source/drivers/net/ethernet/smsc/smc91x.c#L2371">2371</a>         <a href="ident?i=ret">ret</a> = <a href="ident?i=smc_request_attrib">smc_request_attrib</a>(<a href="ident?i=pdev">pdev</a>, ndev);
<a name="L2372" href="source/drivers/net/ethernet/smsc/smc91x.c#L2372">2372</a>         if (<a href="ident?i=ret">ret</a>)
<a name="L2373" href="source/drivers/net/ethernet/smsc/smc91x.c#L2373">2373</a>                 goto out_release_io;
<a name="L2374" href="source/drivers/net/ethernet/smsc/smc91x.c#L2374">2374</a> #if defined(CONFIG_ASSABET_NEPONSET)
<a name="L2375" href="source/drivers/net/ethernet/smsc/smc91x.c#L2375">2375</a>         if (machine_is_assabet() &amp;&amp; <a href="ident?i=machine_has_neponset">machine_has_neponset</a>())
<a name="L2376" href="source/drivers/net/ethernet/smsc/smc91x.c#L2376">2376</a>                 <a href="ident?i=neponset_ncr_set">neponset_ncr_set</a>(<a href="ident?i=NCR_ENET_OSC_EN">NCR_ENET_OSC_EN</a>);
<a name="L2377" href="source/drivers/net/ethernet/smsc/smc91x.c#L2377">2377</a> #endif
<a name="L2378" href="source/drivers/net/ethernet/smsc/smc91x.c#L2378">2378</a>         <a href="ident?i=platform_set_drvdata">platform_set_drvdata</a>(<a href="ident?i=pdev">pdev</a>, ndev);
<a name="L2379" href="source/drivers/net/ethernet/smsc/smc91x.c#L2379">2379</a>         <a href="ident?i=ret">ret</a> = <a href="ident?i=smc_enable_device">smc_enable_device</a>(<a href="ident?i=pdev">pdev</a>);
<a name="L2380" href="source/drivers/net/ethernet/smsc/smc91x.c#L2380">2380</a>         if (<a href="ident?i=ret">ret</a>)
<a name="L2381" href="source/drivers/net/ethernet/smsc/smc91x.c#L2381">2381</a>                 goto out_release_attrib;
<a name="L2382" href="source/drivers/net/ethernet/smsc/smc91x.c#L2382">2382</a> 
<a name="L2383" href="source/drivers/net/ethernet/smsc/smc91x.c#L2383">2383</a>         <a href="ident?i=addr">addr</a> = <a href="ident?i=ioremap">ioremap</a>(<a href="ident?i=res">res</a>-&gt;<a href="ident?i=start">start</a>, <a href="ident?i=SMC_IO_EXTENT">SMC_IO_EXTENT</a>);
<a name="L2384" href="source/drivers/net/ethernet/smsc/smc91x.c#L2384">2384</a>         if (!<a href="ident?i=addr">addr</a>) {
<a name="L2385" href="source/drivers/net/ethernet/smsc/smc91x.c#L2385">2385</a>                 <a href="ident?i=ret">ret</a> = -<a href="ident?i=ENOMEM">ENOMEM</a>;
<a name="L2386" href="source/drivers/net/ethernet/smsc/smc91x.c#L2386">2386</a>                 goto out_release_attrib;
<a name="L2387" href="source/drivers/net/ethernet/smsc/smc91x.c#L2387">2387</a>         }
<a name="L2388" href="source/drivers/net/ethernet/smsc/smc91x.c#L2388">2388</a> 
<a name="L2389" href="source/drivers/net/ethernet/smsc/smc91x.c#L2389">2389</a> #ifdef CONFIG_ARCH_PXA
<a name="L2390" href="source/drivers/net/ethernet/smsc/smc91x.c#L2390">2390</a>         {
<a name="L2391" href="source/drivers/net/ethernet/smsc/smc91x.c#L2391">2391</a>                 struct <a href="ident?i=smc_local">smc_local</a> *<a href="ident?i=lp">lp</a> = <a href="ident?i=netdev_priv">netdev_priv</a>(ndev);
<a name="L2392" href="source/drivers/net/ethernet/smsc/smc91x.c#L2392">2392</a>                 <a href="ident?i=lp">lp</a>-&gt;<a href="ident?i=device">device</a> = &amp;<a href="ident?i=pdev">pdev</a>-&gt;<a href="ident?i=dev">dev</a>;
<a name="L2393" href="source/drivers/net/ethernet/smsc/smc91x.c#L2393">2393</a>                 <a href="ident?i=lp">lp</a>-&gt;<a href="ident?i=physaddr">physaddr</a> = <a href="ident?i=res">res</a>-&gt;<a href="ident?i=start">start</a>;
<a name="L2394" href="source/drivers/net/ethernet/smsc/smc91x.c#L2394">2394</a> 
<a name="L2395" href="source/drivers/net/ethernet/smsc/smc91x.c#L2395">2395</a>         }
<a name="L2396" href="source/drivers/net/ethernet/smsc/smc91x.c#L2396">2396</a> #endif
<a name="L2397" href="source/drivers/net/ethernet/smsc/smc91x.c#L2397">2397</a> 
<a name="L2398" href="source/drivers/net/ethernet/smsc/smc91x.c#L2398">2398</a>         <a href="ident?i=ret">ret</a> = <a href="ident?i=smc_probe">smc_probe</a>(ndev, <a href="ident?i=addr">addr</a>, irq_flags);
<a name="L2399" href="source/drivers/net/ethernet/smsc/smc91x.c#L2399">2399</a>         if (<a href="ident?i=ret">ret</a> != 0)
<a name="L2400" href="source/drivers/net/ethernet/smsc/smc91x.c#L2400">2400</a>                 goto out_iounmap;
<a name="L2401" href="source/drivers/net/ethernet/smsc/smc91x.c#L2401">2401</a> 
<a name="L2402" href="source/drivers/net/ethernet/smsc/smc91x.c#L2402">2402</a>         <a href="ident?i=smc_request_datacs">smc_request_datacs</a>(<a href="ident?i=pdev">pdev</a>, ndev);
<a name="L2403" href="source/drivers/net/ethernet/smsc/smc91x.c#L2403">2403</a> 
<a name="L2404" href="source/drivers/net/ethernet/smsc/smc91x.c#L2404">2404</a>         return 0;
<a name="L2405" href="source/drivers/net/ethernet/smsc/smc91x.c#L2405">2405</a> 
<a name="L2406" href="source/drivers/net/ethernet/smsc/smc91x.c#L2406">2406</a>  out_iounmap:
<a name="L2407" href="source/drivers/net/ethernet/smsc/smc91x.c#L2407">2407</a>         <a href="ident?i=iounmap">iounmap</a>(<a href="ident?i=addr">addr</a>);
<a name="L2408" href="source/drivers/net/ethernet/smsc/smc91x.c#L2408">2408</a>  out_release_attrib:
<a name="L2409" href="source/drivers/net/ethernet/smsc/smc91x.c#L2409">2409</a>         <a href="ident?i=smc_release_attrib">smc_release_attrib</a>(<a href="ident?i=pdev">pdev</a>, ndev);
<a name="L2410" href="source/drivers/net/ethernet/smsc/smc91x.c#L2410">2410</a>  out_release_io:
<a name="L2411" href="source/drivers/net/ethernet/smsc/smc91x.c#L2411">2411</a>         <a href="ident?i=release_mem_region">release_mem_region</a>(<a href="ident?i=res">res</a>-&gt;<a href="ident?i=start">start</a>, <a href="ident?i=SMC_IO_EXTENT">SMC_IO_EXTENT</a>);
<a name="L2412" href="source/drivers/net/ethernet/smsc/smc91x.c#L2412">2412</a>  out_free_netdev:
<a name="L2413" href="source/drivers/net/ethernet/smsc/smc91x.c#L2413">2413</a>         <a href="ident?i=free_netdev">free_netdev</a>(ndev);
<a name="L2414" href="source/drivers/net/ethernet/smsc/smc91x.c#L2414">2414</a>  <a href="ident?i=out">out</a>:
<a name="L2415" href="source/drivers/net/ethernet/smsc/smc91x.c#L2415">2415</a>         <a href="ident?i=pr_info">pr_info</a>(<i>"%s: not found (%d).\n"</i>, <a href="ident?i=CARDNAME">CARDNAME</a>, <a href="ident?i=ret">ret</a>);
<a name="L2416" href="source/drivers/net/ethernet/smsc/smc91x.c#L2416">2416</a> 
<a name="L2417" href="source/drivers/net/ethernet/smsc/smc91x.c#L2417">2417</a>         return <a href="ident?i=ret">ret</a>;
<a name="L2418" href="source/drivers/net/ethernet/smsc/smc91x.c#L2418">2418</a> }
<a name="L2419" href="source/drivers/net/ethernet/smsc/smc91x.c#L2419">2419</a> 
<a name="L2420" href="source/drivers/net/ethernet/smsc/smc91x.c#L2420">2420</a> static int <a href="ident?i=smc_drv_remove">smc_drv_remove</a>(struct <a href="ident?i=platform_device">platform_device</a> *<a href="ident?i=pdev">pdev</a>)
<a name="L2421" href="source/drivers/net/ethernet/smsc/smc91x.c#L2421">2421</a> {
<a name="L2422" href="source/drivers/net/ethernet/smsc/smc91x.c#L2422">2422</a>         struct <a href="ident?i=net_device">net_device</a> *ndev = <a href="ident?i=platform_get_drvdata">platform_get_drvdata</a>(<a href="ident?i=pdev">pdev</a>);
<a name="L2423" href="source/drivers/net/ethernet/smsc/smc91x.c#L2423">2423</a>         struct <a href="ident?i=smc_local">smc_local</a> *<a href="ident?i=lp">lp</a> = <a href="ident?i=netdev_priv">netdev_priv</a>(ndev);
<a name="L2424" href="source/drivers/net/ethernet/smsc/smc91x.c#L2424">2424</a>         struct <a href="ident?i=resource">resource</a> *<a href="ident?i=res">res</a>;
<a name="L2425" href="source/drivers/net/ethernet/smsc/smc91x.c#L2425">2425</a> 
<a name="L2426" href="source/drivers/net/ethernet/smsc/smc91x.c#L2426">2426</a>         <a href="ident?i=unregister_netdev">unregister_netdev</a>(ndev);
<a name="L2427" href="source/drivers/net/ethernet/smsc/smc91x.c#L2427">2427</a> 
<a name="L2428" href="source/drivers/net/ethernet/smsc/smc91x.c#L2428">2428</a>         <a href="ident?i=free_irq">free_irq</a>(ndev-&gt;<a href="ident?i=irq">irq</a>, ndev);
<a name="L2429" href="source/drivers/net/ethernet/smsc/smc91x.c#L2429">2429</a> 
<a name="L2430" href="source/drivers/net/ethernet/smsc/smc91x.c#L2430">2430</a> #ifdef CONFIG_ARCH_PXA
<a name="L2431" href="source/drivers/net/ethernet/smsc/smc91x.c#L2431">2431</a>         if (<a href="ident?i=lp">lp</a>-&gt;<a href="ident?i=dma_chan">dma_chan</a>)
<a name="L2432" href="source/drivers/net/ethernet/smsc/smc91x.c#L2432">2432</a>                 <a href="ident?i=dma_release_channel">dma_release_channel</a>(<a href="ident?i=lp">lp</a>-&gt;<a href="ident?i=dma_chan">dma_chan</a>);
<a name="L2433" href="source/drivers/net/ethernet/smsc/smc91x.c#L2433">2433</a> #endif
<a name="L2434" href="source/drivers/net/ethernet/smsc/smc91x.c#L2434">2434</a>         <a href="ident?i=iounmap">iounmap</a>(<a href="ident?i=lp">lp</a>-&gt;<a href="ident?i=base">base</a>);
<a name="L2435" href="source/drivers/net/ethernet/smsc/smc91x.c#L2435">2435</a> 
<a name="L2436" href="source/drivers/net/ethernet/smsc/smc91x.c#L2436">2436</a>         <a href="ident?i=smc_release_datacs">smc_release_datacs</a>(<a href="ident?i=pdev">pdev</a>,ndev);
<a name="L2437" href="source/drivers/net/ethernet/smsc/smc91x.c#L2437">2437</a>         <a href="ident?i=smc_release_attrib">smc_release_attrib</a>(<a href="ident?i=pdev">pdev</a>,ndev);
<a name="L2438" href="source/drivers/net/ethernet/smsc/smc91x.c#L2438">2438</a> 
<a name="L2439" href="source/drivers/net/ethernet/smsc/smc91x.c#L2439">2439</a>         <a href="ident?i=res">res</a> = <a href="ident?i=platform_get_resource_byname">platform_get_resource_byname</a>(<a href="ident?i=pdev">pdev</a>, <a href="ident?i=IORESOURCE_MEM">IORESOURCE_MEM</a>, <i>"smc91x-regs"</i>);
<a name="L2440" href="source/drivers/net/ethernet/smsc/smc91x.c#L2440">2440</a>         if (!<a href="ident?i=res">res</a>)
<a name="L2441" href="source/drivers/net/ethernet/smsc/smc91x.c#L2441">2441</a>                 <a href="ident?i=res">res</a> = <a href="ident?i=platform_get_resource">platform_get_resource</a>(<a href="ident?i=pdev">pdev</a>, <a href="ident?i=IORESOURCE_MEM">IORESOURCE_MEM</a>, 0);
<a name="L2442" href="source/drivers/net/ethernet/smsc/smc91x.c#L2442">2442</a>         <a href="ident?i=release_mem_region">release_mem_region</a>(<a href="ident?i=res">res</a>-&gt;<a href="ident?i=start">start</a>, <a href="ident?i=SMC_IO_EXTENT">SMC_IO_EXTENT</a>);
<a name="L2443" href="source/drivers/net/ethernet/smsc/smc91x.c#L2443">2443</a> 
<a name="L2444" href="source/drivers/net/ethernet/smsc/smc91x.c#L2444">2444</a>         <a href="ident?i=free_netdev">free_netdev</a>(ndev);
<a name="L2445" href="source/drivers/net/ethernet/smsc/smc91x.c#L2445">2445</a> 
<a name="L2446" href="source/drivers/net/ethernet/smsc/smc91x.c#L2446">2446</a>         return 0;
<a name="L2447" href="source/drivers/net/ethernet/smsc/smc91x.c#L2447">2447</a> }
<a name="L2448" href="source/drivers/net/ethernet/smsc/smc91x.c#L2448">2448</a> 
<a name="L2449" href="source/drivers/net/ethernet/smsc/smc91x.c#L2449">2449</a> static int <a href="ident?i=smc_drv_suspend">smc_drv_suspend</a>(struct <a href="ident?i=device">device</a> *<a href="ident?i=dev">dev</a>)
<a name="L2450" href="source/drivers/net/ethernet/smsc/smc91x.c#L2450">2450</a> {
<a name="L2451" href="source/drivers/net/ethernet/smsc/smc91x.c#L2451">2451</a>         struct <a href="ident?i=platform_device">platform_device</a> *<a href="ident?i=pdev">pdev</a> = <a href="ident?i=to_platform_device">to_platform_device</a>(<a href="ident?i=dev">dev</a>);
<a name="L2452" href="source/drivers/net/ethernet/smsc/smc91x.c#L2452">2452</a>         struct <a href="ident?i=net_device">net_device</a> *ndev = <a href="ident?i=platform_get_drvdata">platform_get_drvdata</a>(<a href="ident?i=pdev">pdev</a>);
<a name="L2453" href="source/drivers/net/ethernet/smsc/smc91x.c#L2453">2453</a> 
<a name="L2454" href="source/drivers/net/ethernet/smsc/smc91x.c#L2454">2454</a>         if (ndev) {
<a name="L2455" href="source/drivers/net/ethernet/smsc/smc91x.c#L2455">2455</a>                 if (<a href="ident?i=netif_running">netif_running</a>(ndev)) {
<a name="L2456" href="source/drivers/net/ethernet/smsc/smc91x.c#L2456">2456</a>                         <a href="ident?i=netif_device_detach">netif_device_detach</a>(ndev);
<a name="L2457" href="source/drivers/net/ethernet/smsc/smc91x.c#L2457">2457</a>                         <a href="ident?i=smc_shutdown">smc_shutdown</a>(ndev);
<a name="L2458" href="source/drivers/net/ethernet/smsc/smc91x.c#L2458">2458</a>                         <a href="ident?i=smc_phy_powerdown">smc_phy_powerdown</a>(ndev);
<a name="L2459" href="source/drivers/net/ethernet/smsc/smc91x.c#L2459">2459</a>                 }
<a name="L2460" href="source/drivers/net/ethernet/smsc/smc91x.c#L2460">2460</a>         }
<a name="L2461" href="source/drivers/net/ethernet/smsc/smc91x.c#L2461">2461</a>         return 0;
<a name="L2462" href="source/drivers/net/ethernet/smsc/smc91x.c#L2462">2462</a> }
<a name="L2463" href="source/drivers/net/ethernet/smsc/smc91x.c#L2463">2463</a> 
<a name="L2464" href="source/drivers/net/ethernet/smsc/smc91x.c#L2464">2464</a> static int <a href="ident?i=smc_drv_resume">smc_drv_resume</a>(struct <a href="ident?i=device">device</a> *<a href="ident?i=dev">dev</a>)
<a name="L2465" href="source/drivers/net/ethernet/smsc/smc91x.c#L2465">2465</a> {
<a name="L2466" href="source/drivers/net/ethernet/smsc/smc91x.c#L2466">2466</a>         struct <a href="ident?i=platform_device">platform_device</a> *<a href="ident?i=pdev">pdev</a> = <a href="ident?i=to_platform_device">to_platform_device</a>(<a href="ident?i=dev">dev</a>);
<a name="L2467" href="source/drivers/net/ethernet/smsc/smc91x.c#L2467">2467</a>         struct <a href="ident?i=net_device">net_device</a> *ndev = <a href="ident?i=platform_get_drvdata">platform_get_drvdata</a>(<a href="ident?i=pdev">pdev</a>);
<a name="L2468" href="source/drivers/net/ethernet/smsc/smc91x.c#L2468">2468</a> 
<a name="L2469" href="source/drivers/net/ethernet/smsc/smc91x.c#L2469">2469</a>         if (ndev) {
<a name="L2470" href="source/drivers/net/ethernet/smsc/smc91x.c#L2470">2470</a>                 struct <a href="ident?i=smc_local">smc_local</a> *<a href="ident?i=lp">lp</a> = <a href="ident?i=netdev_priv">netdev_priv</a>(ndev);
<a name="L2471" href="source/drivers/net/ethernet/smsc/smc91x.c#L2471">2471</a>                 <a href="ident?i=smc_enable_device">smc_enable_device</a>(<a href="ident?i=pdev">pdev</a>);
<a name="L2472" href="source/drivers/net/ethernet/smsc/smc91x.c#L2472">2472</a>                 if (<a href="ident?i=netif_running">netif_running</a>(ndev)) {
<a name="L2473" href="source/drivers/net/ethernet/smsc/smc91x.c#L2473">2473</a>                         <a href="ident?i=smc_reset">smc_reset</a>(ndev);
<a name="L2474" href="source/drivers/net/ethernet/smsc/smc91x.c#L2474">2474</a>                         <a href="ident?i=smc_enable">smc_enable</a>(ndev);
<a name="L2475" href="source/drivers/net/ethernet/smsc/smc91x.c#L2475">2475</a>                         if (<a href="ident?i=lp">lp</a>-&gt;phy_type != 0)
<a name="L2476" href="source/drivers/net/ethernet/smsc/smc91x.c#L2476">2476</a>                                 <a href="ident?i=smc_phy_configure">smc_phy_configure</a>(&amp;<a href="ident?i=lp">lp</a>-&gt;phy_configure);
<a name="L2477" href="source/drivers/net/ethernet/smsc/smc91x.c#L2477">2477</a>                         <a href="ident?i=netif_device_attach">netif_device_attach</a>(ndev);
<a name="L2478" href="source/drivers/net/ethernet/smsc/smc91x.c#L2478">2478</a>                 }
<a name="L2479" href="source/drivers/net/ethernet/smsc/smc91x.c#L2479">2479</a>         }
<a name="L2480" href="source/drivers/net/ethernet/smsc/smc91x.c#L2480">2480</a>         return 0;
<a name="L2481" href="source/drivers/net/ethernet/smsc/smc91x.c#L2481">2481</a> }
<a name="L2482" href="source/drivers/net/ethernet/smsc/smc91x.c#L2482">2482</a> 
<a name="L2483" href="source/drivers/net/ethernet/smsc/smc91x.c#L2483">2483</a> static struct <a href="ident?i=dev_pm_ops">dev_pm_ops</a> <a href="ident?i=smc_drv_pm_ops">smc_drv_pm_ops</a> = {
<a name="L2484" href="source/drivers/net/ethernet/smsc/smc91x.c#L2484">2484</a>         .<a href="ident?i=suspend">suspend</a>        = <a href="ident?i=smc_drv_suspend">smc_drv_suspend</a>,
<a name="L2485" href="source/drivers/net/ethernet/smsc/smc91x.c#L2485">2485</a>         .<a href="ident?i=resume">resume</a>         = <a href="ident?i=smc_drv_resume">smc_drv_resume</a>,
<a name="L2486" href="source/drivers/net/ethernet/smsc/smc91x.c#L2486">2486</a> };
<a name="L2487" href="source/drivers/net/ethernet/smsc/smc91x.c#L2487">2487</a> 
<a name="L2488" href="source/drivers/net/ethernet/smsc/smc91x.c#L2488">2488</a> static struct <a href="ident?i=platform_driver">platform_driver</a> <a href="ident?i=smc_driver">smc_driver</a> = {
<a name="L2489" href="source/drivers/net/ethernet/smsc/smc91x.c#L2489">2489</a>         .<a href="ident?i=probe">probe</a>          = <a href="ident?i=smc_drv_probe">smc_drv_probe</a>,
<a name="L2490" href="source/drivers/net/ethernet/smsc/smc91x.c#L2490">2490</a>         .<a href="ident?i=remove">remove</a>         = <a href="ident?i=smc_drv_remove">smc_drv_remove</a>,
<a name="L2491" href="source/drivers/net/ethernet/smsc/smc91x.c#L2491">2491</a>         .<a href="ident?i=driver">driver</a>         = {
<a name="L2492" href="source/drivers/net/ethernet/smsc/smc91x.c#L2492">2492</a>                 .<a href="ident?i=name">name</a>   = <a href="ident?i=CARDNAME">CARDNAME</a>,
<a name="L2493" href="source/drivers/net/ethernet/smsc/smc91x.c#L2493">2493</a>                 .<a href="ident?i=pm">pm</a>     = &amp;<a href="ident?i=smc_drv_pm_ops">smc_drv_pm_ops</a>,
<a name="L2494" href="source/drivers/net/ethernet/smsc/smc91x.c#L2494">2494</a>                 .of_match_table   = <a href="ident?i=of_match_ptr">of_match_ptr</a>(<a href="ident?i=smc91x_match">smc91x_match</a>),
<a name="L2495" href="source/drivers/net/ethernet/smsc/smc91x.c#L2495">2495</a>                 .acpi_match_table = <a href="ident?i=smc91x_acpi_match">smc91x_acpi_match</a>,
<a name="L2496" href="source/drivers/net/ethernet/smsc/smc91x.c#L2496">2496</a>         },
<a name="L2497" href="source/drivers/net/ethernet/smsc/smc91x.c#L2497">2497</a> };
<a name="L2498" href="source/drivers/net/ethernet/smsc/smc91x.c#L2498">2498</a> 
<a name="L2499" href="source/drivers/net/ethernet/smsc/smc91x.c#L2499">2499</a> <a href="ident?i=module_platform_driver">module_platform_driver</a>(<a href="ident?i=smc_driver">smc_driver</a>);
<a name="L2500" href="source/drivers/net/ethernet/smsc/smc91x.c#L2500">2500</a> </pre></div><p>
This page was automatically generated by <a href="https://sourceforge.net/projects/lxr/">LXR</a> 0.3.1 (<a href="http://free-electrons.com/pub/source/lxr-0.3.1-fe1.tar.bz2">source</a>).
&nbsp;&bull;&nbsp;
Linux is a registered trademark of Linus Torvalds
&nbsp;&bull;&nbsp;
<a href="http://free-electrons.com/company/contact/">Contact us</a>
</p>

<div id="menu">
<ul>
   <li><a href="http://free-electrons.com/">Home</a></li>
   <li><a href="http://free-electrons.com/development/" title="Development">Development</a></li>
   <li><a href="http://free-electrons.com/services/" title="Services">Services</a></li>
   <li><a href="http://free-electrons.com/training/" title="Training">Training</a></li>
   <li><a href="http://free-electrons.com/docs/" title="Docs">Docs</a></li>
   <li><a href="http://free-electrons.com/community/" title="Community">Community</a></li>
   <li><a href="http://free-electrons.com/company/" title="Company">Company</a></li>
   <li><a href="http://free-electrons.com/blog/" title="Blog">Blog</a></li>
</ul>
</div>

</div>
</div>
</body>
</html>
