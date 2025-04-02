using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Net;
using System.Net.NetworkInformation;
using System.Net.Sockets;

namespace Kyanite.Sentinel.Utils
{
	internal static class GeneralUtilities
	{
		internal static string GetLocalIPAddress()
		{
			foreach (NetworkInterface ni in NetworkInterface.GetAllNetworkInterfaces())
			{
				if (ni.OperationalStatus == OperationalStatus.Up &&
					(ni.NetworkInterfaceType == NetworkInterfaceType.Wireless80211 ||
					 ni.NetworkInterfaceType == NetworkInterfaceType.Ethernet))
				{
					foreach (UnicastIPAddressInformation ip in ni.GetIPProperties().UnicastAddresses)
					{
						if (ip.Address.AddressFamily == AddressFamily.InterNetwork)
						{
							return ip.Address.ToString();
						}
					}
				}
			}

			throw new Exception("No active network adapters with an IPv4 address found.");
		}

		internal static int GenerateRandomPort()
		{
			Random random = new Random();
			return random.Next(49152, 65535);
		}
	}
}
